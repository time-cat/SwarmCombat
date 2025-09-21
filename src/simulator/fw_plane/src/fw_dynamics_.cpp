#include "fwp_simulator/fw_dynamics.hpp"
#include <cmath>
#include <algorithm> // for std::lower_bound
#include <iostream>  // <-- 包含 iostream 用于 std::cout

namespace FwSimulator
{

// --- 调试辅助函数 ---
// 检查并打印一个3D向量
void print_vec3d(const std::string& name, const Eigen::Vector3d& vec) {
    bool is_nan = std::isnan(vec.x()) || std::isnan(vec.y()) || std::isnan(vec.z());
    // 设置固定的浮点数表示法和精度
    std::cout << std::fixed << std::setprecision(4);
    if (is_nan) {
        std::cerr << "[!!! FATAL DEBUG !!!] " << name << " contains NaN: [" 
                  << vec.x() << ", " << vec.y() << ", " << vec.z() << "]" << std::endl;
    } else {
        std::cout << "[DEBUG] " << std::setw(25) << std::left << name << ": [" 
                  << std::setw(8) << vec.x() << ", " << std::setw(8) << vec.y() << ", " << std::setw(8) << vec.z() << "]" << std::endl;
    }
}

// 检查并打印一个6D向量 (力和力矩)
void print_fm6d(const std::string& name, const Eigen::Matrix<double, 6, 1>& fm) {
    bool is_nan = false;
    for (int i = 0; i < 6; ++i) {
        if (std::isnan(fm(i))) {
            is_nan = true;
            break;
        }
    }
    std::cout << std::fixed << std::setprecision(4);
    if (is_nan) {
        std::cerr << "[!!! FATAL DEBUG !!!] " << name << " contains NaN: ["
                  << fm(0) << ", " << fm(1) << ", " << fm(2) << " | "
                  << fm(3) << ", " << fm(4) << ", " << fm(5) << "]" << std::endl;
    } else {
        std::cout << "[DEBUG] " << std::setw(25) << std::left << name << ": F=[" 
                  << std::setw(8) << fm(0) << ", " << std::setw(8) << fm(1) << ", " << std::setw(8) << fm(2) << "] M=["
                  << std::setw(8) << fm(3) << ", " << std::setw(8) << fm(4) << ", " << std::setw(8) << fm(5) << "]" << std::endl;
    }
}

FwDynamics::FwDynamics()
{
    // --- Physical Parameters (Aerosonde UAV) ---
    mass_ = 8.5;       // kg
    g_ = 9.80665;       // m/s^2
    J_ = Eigen::Matrix3d::Zero();
    J_(0, 0) = 0.8244;  // Ixx
    J_(1, 1) = 1.135;   // Iyy
    J_(2, 2) = 1.759;   // Izz
    J_(0, 2) = 0.1204;  // Ixz (product of inertia)
    J_(2, 0) = J_(0, 2);
    J_inv_ = J_.inverse();

    // --- Aerodynamic Parameters (Aerosonde UAV) ---
    S_wing_ = 0.55;
    b_wing_ = 2.8956;
    c_chord_ = 0.18994;
    rho_ = 1.225;

    // Stall angles
    alpha_stall_pos_ = 0.30; // ~17.2 degrees
    alpha_stall_neg_ = -0.30;

    // --- Populate Aerodynamic Tables (Non-linear model for Aerosonde) ---
    // Data is representative of a typical UAV's lift/drag/moment curves.
    // Angle of attack is in radians.
    // CL: Lift Coefficient
    CL_table_ = {
        {-0.523, -0.7}, {-0.262, 0.0}, {0.0, 0.2}, {0.262, 1.0}, {0.30, 1.1},
        {0.349, 0.95}, {0.523, 0.8}
    };
    // CD: Drag Coefficient (includes induced drag)
    CD_table_ = {
        {-0.523, 0.1}, {-0.262, 0.04}, {0.0, 0.03}, {0.262, 0.1}, {0.30, 0.15},
        {0.349, 0.25}, {0.523, 0.4}
    };
    // Cm: Pitching Moment Coefficient
    Cm_table_ = {
        {-0.523, 0.2}, {-0.262, 0.1}, {0.0, 0.0}, {-0.262, -0.15}, {-0.30, -0.2},
        {-0.349, -0.18}, {-0.523, -0.15}
    };

    // --- Stability and Control Derivatives (Aerosonde) ---
    // Longitudinal
    C_L_q_ = 7.95;       C_L_delta_e_ = 0.35;
    C_D_q_ = 0.0;        C_D_delta_e_ = 0.0; // Often negligible
    C_m_q_ = -21.5;      C_m_delta_e_ = -1.5;

    // Lateral-Directional
    C_Y_beta_ = -0.5;   C_Y_p_ = 0.0;        C_Y_r_ = 0.2;       C_Y_delta_a_ = 0.0;        C_Y_delta_r_ = 0.15;
    C_l_beta_ = -0.15;  C_l_p_ = -12.5;      C_l_r_ = 2.5;       C_l_delta_a_ = 0.25;       C_l_delta_r_ = 0.05;
    C_n_beta_ = 0.08;   C_n_p_ = -1.25;      C_n_r_ = -4.75;     C_n_delta_a_ = 0.03;       C_n_delta_r_ = -0.09;

    // --- Init State & Input ---
    state_.pos.setZero();
    state_.vel.setZero();
    state_.R = Eigen::Matrix3d::Identity();
    state_.omega.setZero();
    input_ = {0.0, 0.0, 0.0, 0.0};
    sim_step_ = 0.001;
    acc_ned_.setZero();
}

/**
 * @brief This is the new, high-fidelity core of the simulation.
 */
Eigen::Matrix<double, 6, 1> 
FwDynamics::calculateAeroForceAndMoment(const State& state, const Input& input) const
{
    Eigen::Matrix<double, 6, 1> fm;
    fm.setZero();

    // --- 1. Extract state variables ---
    double u = state.vel.x();
    double v = state.vel.y();
    double w = state.vel.z();
    double p = state.omega.x();
    double q = state.omega.y();
    double r = state.omega.z();

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "\n----------- Aero Calculation Step -----------" << std::endl;
    std::cout << "[DEBUG] Body Vel (u,v,w): " << u << ", " << v << ", " << w << std::endl;
    std::cout << "[DEBUG] Body Rates (p,q,r): " << p << ", " << q << ", " << r << std::endl;

    double Va = state.vel.norm();
    // std::cout << "[DEBUG] Airspeed Va: " << Va << std::endl;
    if (Va < 1.0) { // Avoid division by zero at rest
        // std::cerr << "[!!! WARN DEBUG !!!] Airspeed is near zero. Returning zero forces." << std::endl;
        return fm;
    }

    // --- 2. Calculate Angle of Attack (alpha) and Sideslip (beta) ---
    double alpha = atan2(w, u);
    double beta_arg = v / Va;
    beta_arg = std::max(-1.0, std::min(1.0, beta_arg)); // Clamp to [-1.0, 1.0]
    double beta = asin(beta_arg);
    // double beta = asin(v / Va);

    // --- 3. Implement Stall Model ---
    // We use a sigmoid to blend the linear and non-linear (table) lift models
    // This creates a smooth transition into and out of the stall.
    double sigma = sigmoid(15.0 * (alpha - alpha_stall_pos_)) + sigmoid(-15.0 * (alpha - alpha_stall_neg_));

    // --- 4. Coefficient Buildup ---
    // Interpolate basic coefficients from tables
    double CL_table = interpolate1D(CL_table_, alpha);
    double CD_table = interpolate1D(CD_table_, alpha);
    double Cm_table = interpolate1D(Cm_table_, alpha);

    // Get linear coefficients for high-alpha region (deep stall)
    double CL_linear = 2.0 * M_PI * alpha; // From thin airfoil theory

    // Blend the models using the sigmoid
    double CL_alpha_blended = (1.0 - sigma) * CL_table + sigma * CL_linear;
    
    // Non-dimensional rates
    double p_hat = (b_wing_ * p) / (2.0 * Va);
    double q_hat = (c_chord_ * q) / (2.0 * Va);
    double r_hat = (b_wing_ * r) / (2.0 * Va);

    // TOTAL Coefficients
    double CL = CL_alpha_blended + C_L_q_ * q_hat + C_L_delta_e_ * input.elevator;
    double CD = CD_table + C_D_q_ * q_hat + C_D_delta_e_ * input.elevator; // Often simplified
    double CY = C_Y_beta_ * beta + C_Y_p_ * p_hat + C_Y_r_ * r_hat + C_Y_delta_a_ * input.aileron + C_Y_delta_r_ * input.rudder;

    double Cm = Cm_table + C_m_q_ * q_hat + C_m_delta_e_ * input.elevator;
    double Cl = C_l_beta_ * beta + C_l_p_ * p_hat + C_l_r_ * r_hat + C_l_delta_a_ * input.aileron + C_l_delta_r_ * input.rudder;
    double Cn = C_n_beta_ * beta + C_n_p_ * p_hat + C_n_r_ * r_hat + C_n_delta_a_ * input.aileron + C_n_delta_r_ * input.rudder;
    
    // --- 5. Calculate Forces and Moments ---
    double q_bar = 0.5 * rho_ * Va * Va; // Dynamic pressure

    // Forces in wind frame (L, D, Y)
    double Lift = q_bar * S_wing_ * CL;
    double Drag = q_bar * S_wing_ * CD;
    double SideForce = q_bar * S_wing_ * CY;

    // Transform forces from wind to body frame
    Eigen::Vector3d force_wind(-Drag, SideForce, -Lift);
    Eigen::Matrix3d R_wind_to_body;
    R_wind_to_body = Eigen::AngleAxisd(beta, Eigen::Vector3d::UnitZ()).inverse() * 
                     Eigen::AngleAxisd(alpha, Eigen::Vector3d::UnitY()).inverse();
    Eigen::Vector3d force_body = R_wind_to_body * force_wind;
    
    // Moments in body frame
    Eigen::Vector3d moment_body;
    moment_body.x() = q_bar * S_wing_ * b_wing_ * Cl;
    moment_body.y() = q_bar * S_wing_ * c_chord_ * Cm;
    moment_body.z() = q_bar * S_wing_ * b_wing_ * Cn;

    fm.head<3>() = force_body;
    fm.tail<3>() = moment_body;

    print_fm6d("Final Aero F/M", fm);
    return fm;
}


// --- Helper Functions ---
double 
FwDynamics::sigmoid(double x) const
{
    return 1.0 / (1.0 + exp(-x));
}

double 
FwDynamics::interpolate1D(const std::vector<std::pair<double, double>>& table, double key) const
{
    if (table.empty()) return 0.0;

    // Find the first element not less than key
    auto it = std::lower_bound(table.begin(), table.end(), key, 
        [](const std::pair<double, double>& a, double b) {
            return a.first < b;
        });

    // Handle boundary conditions
    if (it == table.begin()) return it->second;
    if (it == table.end()) return (table.end() - 1)->second;

    // Linear interpolation
    double x1 = (it - 1)->first;
    double y1 = (it - 1)->second;
    double x2 = it->first;
    double y2 = it->second;

    return y1 + (y2 - y1) * (key - x1) / (x2 - x1);
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
    const double max_thrust = 200.0; // N
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

    // [CRITICAL CHECK] Final check on derivatives
    for (size_t i = 0; i < dxdt.size(); ++i) {
        if (std::isnan(dxdt[i])) {
            std::cerr << "[!!! FATAL DEBUG !!!] NaN detected in final state derivative vector (dxdt) at index " << i << "!" << std::endl;
            break; 
        }
    }
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

}