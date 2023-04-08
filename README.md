# 使用说明
1. 目前代码里的buffer size和packet size时hard coded
    - buffer size需要修改成1帧数据的字节长度
    - packet size需要修改成buffer size的公约数，并且不能超过1462，可以设置为1个chirp的字节长度
1. 把xWR1xxx雷达的配置文件放到src/mmwave_radar/config目录，修改launch文件的相应参数
2. 启动雷达：roslaunch mmwave_radar start_mmwave_radar.launch
3. 关闭雷达：roslaunch mmwave_radar stop_mmwave_radar.launch
4. 查看雷达话题：rostopic list, rostopic echo /mmwave_adc_data
5. 查看雷达消息格式：rosmsg info mmwave_radar/adcData