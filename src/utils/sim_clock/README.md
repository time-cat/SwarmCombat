2.  **启动**:
    在一个新的终端中，source 你的工作空间并启动 launch 文件：
    ```bash
    source install/setup.bash
    ros2 launch sim_clock start_sim_clock.launch.py rate:=2.0
    ```

3.  **控制**:
    打开另一个终端（同样需要 source `install/setup.bash`）：

    *   **查看 `/clock` 话题**:
        ```bash
        ros2 topic echo /clock
        ```

    *   **暂停时钟**:
        ```bash
        ros2 service call /pause_clock std_srvs/srv/Empty
        ```

    *   **恢复时钟**:
        ```bash
        ros2 service call /resume_clock std_srvs/srv/Empty
        ```

    *   **设置为0.5倍速**:
        ```bash
        ros2 service call /set_clock_rate sim_clock/srv/SetRate "{rate: 0.5}"
        ```