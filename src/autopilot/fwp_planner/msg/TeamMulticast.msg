# ==============================================================================
# 描述: 团队内部组播的战术情报消息。
#      由一个实体（无人机或地面站）发出，包含其所知的最全战场态势图。
# ==============================================================================
std_msgs/Header header

int32 sender_id              
float32 multicast_range

FusedTeammate[] known_teammates   # 已知队友信息表格
FusedEnemy[]    known_enemies     # 已知敌方信息表格

DynamicState dynamic_state      # 发送者完整的状态信息
bool is_alive                              # 当前的存活状态