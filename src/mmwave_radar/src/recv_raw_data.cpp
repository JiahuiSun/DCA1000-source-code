#include "ros/ros.h"
#include "mmwave_radar/adcData.h"
#include <stdio.h>


char strFileName1[255];
char strRecordFilePath[] = "/home/dingrong/Code/DCA1000/DCA1000-source-code/src/mmwave_radar/data/adc_";
char REC_DATA_FILE_EXTENSION[] = ".bin";
int u32DataFileCount = 0;

// 创建一个文件，作为全局变量
void saveData(const mmwave_radar::adcData::ConstPtr& msg_ptr) {
    // 把数据写入文件
    u32DataFileCount++;
    strcpy(strFileName1, strRecordFilePath);
    strcat(strFileName1, std::to_string(u32DataFileCount).c_str());
    strcat(strFileName1, REC_DATA_FILE_EXTENSION);
    FILE *pRecordDataFile = fopen(strFileName1, "wb+");
    fwrite((const char *)& msg_ptr->data, 1, msg_ptr->size, pRecordDataFile);
    fclose(pRecordDataFile);
}


int main(int argc, char* argv[]) {
    // 节点初始化
    ros::init(argc, argv, "recv_raw_data");
    ros::NodeHandle nh;
    // 创建话题订阅对象
    ros::Subscriber sub = nh.subscribe<mmwave_radar::adcData>("mmwave_adc_data", 10, saveData);
    // 创建回调函数，监听收到的话题，把数据保存到文件里
    ros::spin();
    return 0;
}