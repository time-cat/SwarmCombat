#include <chrono>
#include <memory>
#include <string>
#include <functional>

#include "rclcpp/rclcpp.hpp"
#include "rosgraph_msgs/msg/clock.hpp"
#include "std_srvs/srv/empty.hpp"
#include "sim_clock/srv/set_rate.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;
using std::placeholders::_2;

class SimClockNode : public rclcpp::Node
{
public:
    SimClockNode() : Node("sim_clock_node"), current_sim_time_(0, 0, RCL_ROS_TIME), time_step_(0, 0)
    {
        // 1. Declare parameters with default values
        this->declare_parameter<double>("publish_frequency", 100.0);
        this->declare_parameter<double>("initial_rate", 1.0);
        this->declare_parameter<bool>("start_paused", false);
        this->declare_parameter<double>("initial_sim_time", 0.0);
        
        // 2. Get parameters
        this->get_parameter("publish_frequency", publish_frequency_);
        this->get_parameter("initial_rate", current_rate_);
        this->get_parameter("start_paused", is_paused_);
        
        double initial_sim_time_sec;
        this->get_parameter("initial_sim_time", initial_sim_time_sec);

        // Initialize time variables
        current_sim_time_ = rclcpp::Time(static_cast<int64_t>(initial_sim_time_sec * 1e9));
        time_step_ = rclcpp::Duration(std::chrono::nanoseconds(static_cast<int64_t>((current_rate_ / publish_frequency_) * 1e9)));

        // Create publisher for /clock topic (use QoS that matches rosbag play)
        clock_pub_ = this->create_publisher<rosgraph_msgs::msg::Clock>("/clock", rclcpp::QoS(10).transient_local());

        // Create services
        pause_srv_ = this->create_service<std_srvs::srv::Empty>("pause_clock", std::bind(&SimClockNode::pauseCallback, this, _1, _2));
        resume_srv_ = this->create_service<std_srvs::srv::Empty>("resume_clock", std::bind(&SimClockNode::resumeCallback, this, _1, _2));
        set_rate_srv_ = this->create_service<sim_clock::srv::SetRate>("set_clock_rate", std::bind(&SimClockNode::setRateCallback, this, _1, _2));

        // Create a WallTimer for the main loop
        auto timer_period = std::chrono::duration<double>(1.0 / publish_frequency_);
        wall_timer_ = this->create_wall_timer(timer_period, std::bind(&SimClockNode::timerCallback, this));
        
        RCLCPP_INFO(this->get_logger(), "SimClock Node Initialized.");
        RCLCPP_INFO(this->get_logger(), " -> Publish Frequency: %.2f Hz", publish_frequency_);
        RCLCPP_INFO(this->get_logger(), " -> Initial Rate: %.2f x", current_rate_);
        RCLCPP_INFO(this->get_logger(), " -> Initial Sim Time: %.2f s", initial_sim_time_sec);
        RCLCPP_INFO(this->get_logger(), " -> Started in %s state.", is_paused_ ? "PAUSED" : "RUNNING");
    }

private:
    void timerCallback()
    {
        if (!is_paused_)
        {
            rosgraph_msgs::msg::Clock clock_msg;
            clock_msg.clock = current_sim_time_;
            clock_pub_->publish(clock_msg);

            current_sim_time_ += time_step_;
        }
    }

    void pauseCallback(const std::shared_ptr<std_srvs::srv::Empty::Request> req, std::shared_ptr<std_srvs::srv::Empty::Response> res)
    {
        (void)req; // Unused parameter
        (void)res; // Unused parameter
        if (!is_paused_) {
            is_paused_ = true;
            RCLCPP_INFO(this->get_logger(), "Simulation clock PAUSED.");
        }
    }

    void resumeCallback(const std::shared_ptr<std_srvs::srv::Empty::Request> req, std::shared_ptr<std_srvs::srv::Empty::Response> res)
    {
        (void)req; // Unused parameter
        (void)res; // Unused parameter
        if (is_paused_) {
            is_paused_ = false;
            RCLCPP_INFO(this->get_logger(), "Simulation clock RESUMED.");
        }
    }

    void setRateCallback(const std::shared_ptr<sim_clock::srv::SetRate::Request> req, std::shared_ptr<sim_clock::srv::SetRate::Response> res)
    {
        if (req->rate < 0) {
            res->success = false;
            res->message = "Rate cannot be negative.";
            RCLCPP_ERROR(this->get_logger(), "%s", res->message.c_str());
            return;
        }

        current_rate_ = req->rate;
        time_step_ = rclcpp::Duration(std::chrono::nanoseconds(static_cast<int64_t>((current_rate_ / publish_frequency_) * 1e9)));
        res->success = true;
        res->message = "Simulation rate set to " + std::to_string(req->rate);
        RCLCPP_INFO(this->get_logger(), "%s", res->message.c_str());
    }

    rclcpp::TimerBase::SharedPtr                            wall_timer_;
    rclcpp::Publisher<rosgraph_msgs::msg::Clock>::SharedPtr clock_pub_;
    rclcpp::Service<std_srvs::srv::Empty>::SharedPtr        pause_srv_, resume_srv_;
    rclcpp::Service<sim_clock::srv::SetRate>::SharedPtr     set_rate_srv_;
    
    rclcpp::Duration time_step_;
    rclcpp::Time     current_sim_time_;
    
    bool   is_paused_;
    double publish_frequency_;
    double current_rate_;
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SimClockNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}