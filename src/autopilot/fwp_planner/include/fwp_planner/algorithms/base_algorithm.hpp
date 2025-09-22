#ifndef FWP_PLANNER__ALGORITHMS__BASE_ALGORITHM_HPP_
#define FWP_PLANNER__ALGORITHMS__BASE_ALGORITHM_HPP_

#include <map>
#include <string>
#include <vector>

#include <geometry_msgs/msg/point.hpp>
#include <rclcpp/time.hpp>
#include "fwp_planner/types.hpp"
#include "fwp_planner/msg/dynamic_state.hpp"
#include "sim_msgs/msg/fw_control.hpp"

/**
 * @class BaseAlgorithm
 * @brief 算法逻辑的抽象基类接口
 *
 * 定义了无人机决策和运动规划所需的核心功能。
 * 任何具体的算法实现（如APF, RRT*等）都应继承此类并实现其纯虚函数。
 */
class BaseAlgorithm
{
public:
    // 虚析构函数，确保派生类对象能被正确销毁
    virtual ~BaseAlgorithm() = default;

    /**
     * @brief 根据战场态势选择打击目标
     * @param self_state 当前无人机的动态状态
     * @param known_enemies 已知敌方单位的信息
     * @param known_teammates 已知队友的锁定目标信息
     * @return 选定的目标ID，如果没有合适目标则返回-1
     */
    virtual int select_target(
        const fwp_planner::msg::DynamicState& self_state,
        const std::map<int, StoredEnemyInfo>& known_enemies,
        const std::map<int, StoredTeammateInfo>& known_teammates) = 0;

    /**
     * @brief 根据战场态势决策当前是否自爆
     * @param target_id 当前锁定的目标ID
     * @param exp_range 无人机的有效自爆范围
     * @param self_state 当前无人机的动态状态
     * @param known_enemies 已知敌方单位的信息
     * @return 决策是否自爆
     */
    virtual bool decide_explode(
        int target_id,
        double exp_range,
        const fwp_planner::msg::DynamicState& self_state,
        const std::map<int, StoredEnemyInfo>& known_enemies) = 0;

    /**
     * @brief 计算下一步的运动控制指令
     * @param target_id 当前锁定的目标ID
     * @param self_state 当前无人机的动态状态
     * @param known_enemies 已知敌方单位的信息
     * @param known_teammates_dynamic_info 已知队友的完整动态信息
     * @return 生成的固定翼控制指令
     */
    virtual sim_msgs::msg::FwControl calculate_motion(
        int target_id,
        const fwp_planner::msg::DynamicState& self_state,
        const std::map<int, StoredEnemyInfo>& known_enemies,
        const std::map<int, StoredBroadcastInfo>& known_teammates_dynamic_info) = 0;
    
};

#endif // FWP_PLANNER__ALGORITHMS__BASE_ALGORITHM_HPP_