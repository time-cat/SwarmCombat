#include "fwp_simulator/fw_dynamics.hpp"
#include <iostream>

namespace FwSimulator
{

// 构造函数：初始化参数
FwDynamics::FwDynamics()
{
    // --- 初始化物理参数 (以一个小型无人机为例) ---
    mass_ = 2.3; // kg
    g_ = 9.80665; // m/s^2
    
    // 转动惯量矩阵 (示例值, 需要根据具体飞机模型修改)
    J_ = Eigen::Matrix3d::Zero();
    J_(0, 0) = 0.05;  // Ixx
    J_(1, 1) = 0.06;  // Iyy
    J_(2, 2) = 0.1;   // Izz
    J_inv_ = J_.inverse();

    // --- 初始化气动参数 ---
    S_wing_ = 0.25;    // m^2
    b_wing_ = 1.5;     // m
    c_chord_ = 0.18;   // m
    rho_ = 1.225;      // kg/m^3

    // --- 初始化状态 ---
    state_.pos.setZero();
    state_.vel.setZero();
    state_.R = Eigen::Matrix3d::Identity();
    state_.omega.setZero();
    
    // --- 初始化输入 ---
    input_.throttle = 0.0;
    input_.elevator = 0.0;
    input_.aileron = 0.0;
    input_.rudder = 0.0;

    // --- 初始化仿真参数 ---
    sim_step_ = 0.001; // 1ms 仿真步长
    
    acc_ned_.setZero();
}

// 核心：常微分方程
void 
FwDynamics::differentialEquation(const StateVector& x, StateVector& dxdt, double t)
{
    State current_state;
    devectorizeState(current_state, x);

    // --- 1. 计算总的力和力矩 ---
    // 重力 (在机体坐标系下)
    Eigen::Vector3d gravity_force_body = current_state.R.transpose() * Eigen::Vector3d(0, 0, mass_ * g_);
    
    // 空气动力和力矩
    Eigen::Matrix<double, 6, 1> aero_fm = calculateAeroForceAndMoment(current_state, input_);
    Eigen::Vector3d aero_force_body = aero_fm.head<3>();
    Eigen::Vector3d aero_moment_body = aero_fm.tail<3>();

    // 推力 (简化模型：沿机体x轴)
    // 您可以根据需要创建更复杂的推力模型
    const double max_thrust = 30.0; // N
    Eigen::Vector3d thrust_force_body(input_.throttle * max_thrust, 0, 0);

    // 合力与合力矩
    Eigen::Vector3d total_force_body = gravity_force_body + aero_force_body + thrust_force_body;
    Eigen::Vector3d total_moment_body = aero_moment_body;

    // --- 2. 计算状态导数 ---
    State dot_state;

    // 位置导数 (速度从机体坐标系转换到地理坐标系)
    dot_state.pos = current_state.R * current_state.vel;

    // 速度导数 (牛顿第二定律: a = F/m)
    // d(vel)/dt = F/m - omega x vel
    dot_state.vel = total_force_body / mass_ - current_state.omega.cross(current_state.vel);
    
    // 姿态导数 (旋转矩阵导数)
    Eigen::Matrix3d omega_skew;
    omega_skew << 0, -current_state.omega.z(), current_state.omega.y(),
                  current_state.omega.z(), 0, -current_state.omega.x(),
                  -current_state.omega.y(), current_state.omega.x(), 0;
    dot_state.R = current_state.R * omega_skew;
    
    // 角速度导数 (欧拉方程: d(omega)/dt = J_inv * (M - omega x (J*omega)))
    dot_state.omega = J_inv_ * (total_moment_body - current_state.omega.cross(J_ * current_state.omega));
    
    // --- 3. 记录加速度，并向量化导数 ---
    // 计算并存储地理坐标系下的加速度，方便外部读取
    Eigen::Vector3d acceleration_body = total_force_body / mass_;
    acc_ned_ = current_state.R * acceleration_body;

    vectorizeState(dxdt, dot_state);
}


// 运行一个仿真步
void 
FwDynamics::step(const double& start_time, const double& end_time)
{
    StateVector state_vec; // 用于 odeint 的向量化状态
    namespace odeint = boost::numeric::odeint;
    vectorizeState(state_vec, state_);

    // 使用 Runge-Kutta 4 阶积分器
    odeint::runge_kutta4<StateVector> stepper;
    stepper.do_step(
        [this](const StateVector& x, StateVector& dxdt, double t) {
            this->differentialEquation(x, dxdt, t);
        },
        state_vec, start_time, end_time - start_time);
        
    devectorizeState(state_, state_vec); // 更新 state_

    // 保证旋转矩阵 R 的正交性，防止数值误差累积
    Eigen::JacobiSVD<Eigen::Matrix3d> svd(state_.R, Eigen::ComputeFullU | Eigen::ComputeFullV);
    state_.R = svd.matrixU() * svd.matrixV().transpose();
}


// --- 气动力和力矩计算 ---
// 这是简化的模型，您需要根据飞机的具体数据来填充这些系数
Eigen::Matrix<double, 6, 1> 
FwDynamics::calculateAeroForceAndMoment(const State& state, const Input& input) const
{
    Eigen::Matrix<double, 6, 1> fm;
    fm.setZero();
    
    double u = state.vel.x();
    double v = state.vel.y();
    double w = state.vel.z();
    double p = state.omega.x();
    double q = state.omega.y();
    double r = state.omega.z();

    double Va = state.vel.norm();
    if (Va < 0.1) { // 避免速度为零时除法错误
        return fm;
    }

    // 攻角 (alpha) 和侧滑角 (beta)
    double alpha = atan2(w, u);
    double beta = asin(v / Va);

    // 动态压力
    double q_bar = 0.5 * rho_ * Va * Va;

    // --- 升力和阻力系数 (简化的线性模型) ---
    // 您应该用更精确的模型或查表数据替换这里
    double CL_alpha = 4.5;
    double CL_0 = 0.2;
    double CL_q = 3.8;
    double CL_de = 0.4;
    double CL = CL_0 + CL_alpha * alpha + (c_chord_ / (2 * Va)) * CL_q * q + CL_de * input.elevator;

    double CD_0 = 0.02;
    double K_CD = 0.05;
    double CD = CD_0 + K_CD * CL * CL;

    // --- 侧向力系数 ---
    double CY_beta = -0.9;
    double CY_p = 0.0;
    double CY_r = 0.2;
    double CY_dr = 0.15;
    double CY = CY_beta * beta + (b_wing_ / (2 * Va)) * (CY_p * p + CY_r * r) + CY_dr * input.rudder;
    
    // --- 计算风坐标系下的力 ---
    double Lift = q_bar * S_wing_ * CL;
    double Drag = q_bar * S_wing_ * CD;
    double SideForce = q_bar * S_wing_ * CY;

    // --- 将力从风坐标系转换到机体坐标系 ---
    Eigen::Vector3d force_wind( -Drag, SideForce, -Lift );
    Eigen::Matrix3d R_wind_to_body; // 从风坐标系到机体
    R_wind_to_body = Eigen::AngleAxisd(-alpha, Eigen::Vector3d::UnitY()) * Eigen::AngleAxisd(beta, Eigen::Vector3d::UnitZ());
    Eigen::Vector3d force_body = R_wind_to_body * force_wind;
    
    // --- 力矩系数 (简化的线性模型) ---
    double Cl_beta = -0.12;
    double Cl_p = -0.8;
    double Cl_r = 0.1;
    double Cl_da = 0.15;
    double Cl = Cl_beta * beta + (b_wing_ / (2*Va)) * (Cl_p * p + Cl_r * r) + Cl_da * input.aileron;

    double Cm_0 = 0.0;
    double Cm_alpha = -1.5;
    double Cm_q = -7.0;
    double Cm_de = -1.2;
    double Cm = Cm_0 + Cm_alpha * alpha + (c_chord_ / (2 * Va)) * Cm_q * q + Cm_de * input.elevator;

    double Cn_beta = 0.25;
    double Cn_p = -0.02;
    double Cn_r = -0.3;
    double Cn_dr = -0.08;
    double Cn = Cn_beta * beta + (b_wing_ / (2*Va)) * (Cn_p * p + Cn_r * r) + Cn_dr * input.rudder;

    // --- 计算力矩 ---
    Eigen::Vector3d moment_body;
    moment_body.x() = q_bar * S_wing_ * b_wing_ * Cl;  // 滚转力矩 L
    moment_body.y() = q_bar * S_wing_ * c_chord_ * Cm; // 俯仰力矩 M
    moment_body.z() = q_bar * S_wing_ * b_wing_ * Cn;  // 偏航力矩 N

    fm.head<3>() = force_body;
    fm.tail<3>() = moment_body;

    return fm;
}


// --- 实现其他公共接口 ---

void FwDynamics::setState(const State& state)
{
    state_ = state;
}

void FwDynamics::setPosition(const double& n, const double& e, const double& d)
{
    state_.pos << n, e, d;
}

void FwDynamics::setVelocity(const double& u, const double& v, const double& w)
{
    state_.vel << u, v, w;
}

void FwDynamics::setAttitude(const double& roll, const double& pitch, const double& yaw)
{
    Eigen::AngleAxisd rollAngle(roll, Eigen::Vector3d::UnitX());
    Eigen::AngleAxisd pitchAngle(pitch, Eigen::Vector3d::UnitY());
    Eigen::AngleAxisd yawAngle(yaw, Eigen::Vector3d::UnitZ());
    state_.R = yawAngle * pitchAngle * rollAngle;
}

void FwDynamics::setInput(const Input& input)
{
    input_ = input;
}

void FwDynamics::setSimStep(const double& dt)
{
    sim_step_ = dt;
}

FwDynamics::State FwDynamics::getState() const
{
    return state_;
}

Eigen::Vector3d FwDynamics::getPosition() const
{
    return state_.pos;
}

Eigen::Vector3d FwDynamics::getVelocityBody() const
{
    return state_.vel;
}

Eigen::Vector3d FwDynamics::getVelocityNED() const
{
    return state_.R * state_.vel;
}

Eigen::Vector3d FwDynamics::getEulerAngles() const
{
    return state_.R.eulerAngles(2, 1, 0).reverse(); // ZYX 顺序，得到 (roll, pitch, yaw)
}

Eigen::Quaterniond FwDynamics::getQuaternion() const
{
    return Eigen::Quaterniond(state_.R);
}

Eigen::Vector3d FwDynamics::getAngularVelocity() const
{
    return state_.omega;
}

Eigen::Vector3d FwDynamics::getAccelerationNED() const
{
    return acc_ned_;
}

double FwDynamics::getAirspeed() const
{
    return state_.vel.norm();
}

// --- 私有辅助函数实现 ---

void FwDynamics::vectorizeState(StateVector& vec, const State& state)
{
    vec.resize(18);
    // 位置 (3)
    vec[0] = state.pos.x(); vec[1] = state.pos.y(); vec[2] = state.pos.z();
    // 速度 (3)
    vec[3] = state.vel.x(); vec[4] = state.vel.y(); vec[5] = state.vel.z();
    // 旋转矩阵 (9)
    for (int i=0; i<3; ++i) for (int j=0; j<3; ++j) vec[6 + i*3 + j] = state.R(i, j);
    // 角速度 (3)
    vec[15] = state.omega.x(); vec[16] = state.omega.y(); vec[17] = state.omega.z();
}

void FwDynamics::devectorizeState(State& state, const StateVector& vec)
{
    // 位置
    state.pos << vec[0], vec[1], vec[2];
    // 速度
    state.vel << vec[3], vec[4], vec[5];
    // 旋转矩阵
    for (int i=0; i<3; ++i) for (int j=0; j<3; ++j) state.R(i, j) = vec[6 + i*3 + j];
    // 角速度
    state.omega << vec[15], vec[16], vec[17];
}


} // namespace FwDynamics