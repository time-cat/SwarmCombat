#pragma once

#include <boost/numeric/odeint.hpp>
#include <Eigen/Core>
#include <Eigen/Dense>

namespace FwSimulator
{

class FwDynamics
{
public:
    // 使用 std::vector<double> 作为 odeint 的状态向量
    typedef std::vector<double> StateVector;

    // 飞机状态结构体
    struct State
    {
        Eigen::Vector3d pos;      // 位置 (North, East, Down) [m]
        Eigen::Vector3d vel;      // 机体坐标系下的速度 (u, v, w) [m/s]
        Eigen::Matrix3d R;        // 旋转矩阵 (从机体坐标系到地理坐标系)
        Eigen::Vector3d omega;    // 机体坐标系下的角速度 (p, q, r) [rad/s]
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
    };
    
    // 控制输入结构体
    struct Input
    {
        double throttle;      // 油门 (0.0 to 1.0)
        double elevator;      // 升降舵偏转 [rad]
        double aileron;       // 副翼偏转 [rad]
        double rudder;        // 方向舵偏转 [rad]
    };

    FwDynamics();

    // --- 设置器 ---
    void setState(const State &state);
    void setPosition(const double& n, const double& e, const double& d);
    void setVelocity(const double& u, const double& v, const double& w);
    void setAttitude(const double& roll, const double& pitch, const double& yaw);
    void setInput(const Input &input);
    void setSimStep(const double& dt);
    
    // --- 获取器 ---
    State getState() const;
    Eigen::Vector3d getPosition() const;
    Eigen::Vector3d getVelocityBody() const; // 获取机体速度
    Eigen::Vector3d getVelocityNED() const;  // 获取地理速度
    Eigen::Vector3d getEulerAngles() const;  // 获取欧拉角 (roll, pitch, yaw)
    Eigen::Quaterniond getQuaternion() const;
    Eigen::Vector3d getAngularVelocity() const;
    Eigen::Vector3d getAccelerationNED() const; // 获取地理坐标系下的加速度
    double getAirspeed() const;

    // --- 核心动力学函数 ---
    // 被 odeint 调用的微分方程
    void differentialEquation(const StateVector& x, StateVector& dxdt, double t);

    // 运行一个仿真步长
    void step(const double& start_time, const double& end_time);

private:
    // --- 物理和气动参数 (可以根据您的具体飞机进行修改) ---
    // 物理参数
    double mass_;         // 质量 [kg]
    double g_;            // 重力加速度 [m/s^2]
    Eigen::Matrix3d J_;   // 转动惯量矩阵 [kg*m^2]
    Eigen::Matrix3d J_inv_;// 转动惯量矩阵的逆

    // 气动参数
    double S_wing_;       // 机翼面积 [m^2]
    double b_wing_;       // 翼展 [m]
    double c_chord_;      // 平均气动弦长 [m]
    double rho_;          // 空气密度 [kg/m^3]

    // --- 内部状态和变量 ---
    State state_;         // 当前状态
    Input input_;         // 当前输入
    double sim_step_;     // 仿真步长 [s]
    Eigen::Vector3d force_and_moment_; // 存储计算的力和力矩
    Eigen::Vector3d acc_ned_; // 地理坐标系下的加速度

    // --- 私有辅助函数 ---
    void vectorizeState(StateVector& vec, const State& state);
    void devectorizeState(State& state, const StateVector& vec);
    
    // 计算气动力和力矩
    Eigen::Matrix<double, 6, 1> calculateAeroForceAndMoment(const State& state, const Input& input) const;
};

} // namespace FixedWingSim
