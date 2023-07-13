#pragma once

#include <ros/ros.h>
#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/TransformStamped.h>
#include <sensor_msgs/LaserScan.h>
#include <sensor_msgs/PointCloud2.h>

#include <string>

using namespace std;

class TFProcessor
{
private:
    tf2_ros::Buffer m_tfBuffer;
    tf2_ros::TransformListener m_tfListener;

    ros::Publisher* pTFPublisherForLidar1 = nullptr;
    ros::Publisher* pTFPublisherForLidar2 = nullptr;
    ros::Publisher* pTFPublisherForCamera = nullptr;
  
public:
    TFProcessor();
    ~TFProcessor() = default;

    void enlist_publisher_for_lidar1(ros::Publisher& publisher) {pTFPublisherForLidar1 = &publisher;}
    void enlist_publisher_for_lidar2(ros::Publisher& publisher) {pTFPublisherForLidar2 = &publisher;}
    void enlist_publisher_for_camera(ros::Publisher& publisher) {pTFPublisherForCamera = &publisher;}

    void publish_transformed_message_for_lidar1(const sensor_msgs::LaserScan::ConstPtr& msg);
    void publish_transformed_message_for_lidar2(const sensor_msgs::LaserScan::ConstPtr& msg);
    void publish_transformed_message_for_camera(const sensor_msgs::PointCloud2::ConstPtr& msg);
};