#include "ScanListener.h"
#include "TFProcessor.h"

void ScanListener::scan_callback_for_lidar1(const sensor_msgs::LaserScan::ConstPtr& msg)
{
    //ROS_INFO("I heard scan1: [%f]", msg->ranges[0]);
    if(pTFProcessor != nullptr)
    {
        pTFProcessor->publish_transformed_message_for_lidar1(msg);
    }
}



void ScanListener::scan_callback_for_lidar2(const sensor_msgs::LaserScan::ConstPtr& msg)
{
    //ROS_INFO("I heard scan2: [%f]", msg->ranges[0]);

    if(pTFProcessor != nullptr)
    {
        pTFProcessor->publish_transformed_message_for_lidar2(msg);
    }
}



void ScanListener::scan_callback_for_camera(const sensor_msgs::PointCloud2::ConstPtr& msg)
{
    //ROS_INFO("I heard camera");

    if(pTFProcessor != nullptr)
    {
        pTFProcessor->publish_transformed_message_for_camera(msg);
    }
}