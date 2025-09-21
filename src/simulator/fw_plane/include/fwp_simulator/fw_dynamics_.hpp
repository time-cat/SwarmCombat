#ifndef FW_DYNAMICS_HPP_
#define FW_DYNAMICS_HPP_

#include <Eigen/Dense>
#include <boost/numeric/odeint.hpp>
#include <vector>
#include <utility> // for std::pair

namespace FwSimulator
{

// The StateVector for boost::odeint remains the same
using StateVector = std::vector<double>;

class FwDynamics
{
public:
    // --- Public Structs ---
    struct State {
        Eigen::Vector3d pos;    // Position in NED frame {n, e, d}
        Eigen::Vector3d vel;    // Velocity in Body frame {u, v, w}
        Eigen::Matrix3d R;      // Rotation matrix (Body to NED)
        Eigen::Vector3d omega;  // Angular velocity in Body frame {p, q, r}
    };

    struct Input {
        double throttle; // Throttle command [0, 1]
        double elevator; // Elevator deflection [rad]
        double aileron;  // Aileron deflection [rad]
        double rudder;   // Rudder deflection [rad]
    };

    // --- Constructor ---
    FwDynamics();

    // --- Public Methods ---
    void step(const double& start_time, const double& end_time);

    // Setters
    void setState(const State& state);
    void setPosition(const double& n, const double& e, const double& d);
    void setVelocity(const double& u, const double& v, const double& w);
    void setAttitude(const double& roll, const double& pitch, const double& yaw);
    void setInput(const Input& input);
    void setSimStep(const double& dt);

    // Getters
    State getState() const;
    Eigen::Vector3d getPosition() const;
    Eigen::Vector3d getVelocityBody() const; // 获取机体速度
    Eigen::Vector3d getVelocityNED() const;  // 获取地理速度
    Eigen::Vector3d getEulerAngles() const;  // 获取欧拉角 (roll, pitch, yaw)
    Eigen::Quaterniond getQuaternion() const;
    Eigen::Vector3d getAngularVelocity() const;
    Eigen::Vector3d getAccelerationNED() const; // 获取地理坐标系下的加速度
    double getAirspeed() const;

private:
    // --- Private Methods ---
    void differentialEquation(const StateVector& x, StateVector& dxdt, double t);
    Eigen::Matrix<double, 6, 1> calculateAeroForceAndMoment(const State& state, const Input& input) const;
    
    // Helper for state vectorization
    void vectorizeState(StateVector& vec, const State& state);
    void devectorizeState(State& state, const StateVector& vec);
    
    // Helper for aerodynamics
    double interpolate1D(const std::vector<std::pair<double, double>>& table, double key) const;
    double sigmoid(double x) const;

    // --- State & Input ---
    State state_;
    Input input_;
    Eigen::Vector3d acc_ned_; // Acceleration in NED frame

    // --- Simulation Parameters ---
    double sim_step_;

    // --- Physical Parameters (Aerosonde UAV) ---
    double mass_;
    double g_;
    Eigen::Matrix3d J_, J_inv_;
    
    // --- Aerodynamic Parameters ---
    double S_wing_;   // Wing surface area
    double b_wing_;   // Wingspan
    double c_chord_;  // Mean aerodynamic chord
    double rho_;      // Air density
    
    // Non-linear aerodynamic data tables (angle of attack vs. coefficient)
    std::vector<std::pair<double, double>> CL_table_; // Lift
    std::vector<std::pair<double, double>> CD_table_; // Drag
    std::vector<std::pair<double, double>> Cm_table_; // Pitching Moment
    
    // Stability and Control Derivatives (assumed constant for simplicity)
    // Lateral-Directional
    double C_Y_beta_, C_Y_p_, C_Y_r_, C_Y_delta_a_, C_Y_delta_r_;
    double C_l_beta_, C_l_p_, C_l_r_, C_l_delta_a_, C_l_delta_r_;
    double C_n_beta_, C_n_p_, C_n_r_, C_n_delta_a_, C_n_delta_r_;
    // Longitudinal (Damping and Control only, basic is from table)
    double C_L_q_, C_L_delta_e_;
    double C_D_q_, C_D_delta_e_;
    double C_m_q_, C_m_delta_e_;

    // Stall model parameters
    double alpha_stall_pos_; // Positive stall angle [rad]
    double alpha_stall_neg_; // Negative stall angle [rad]
};

} // namespace FwSimulator

#endif // FW_DYNAMICS_HPP_