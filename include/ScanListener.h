#pragma once

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <sensor_msgs/PointCloud2.h>

#include <string>
#include <functional>

using namespace std;

class TFProcessor;

class ScanListener
{
private:
    u_int32_t m_lidar1ScanCount = 0;
    u_int32_t m_lidar2ScanCount = 0;
    u_int32_t m_cameraScanCount = 0;

    string m_topicNameForLidar1 = "/scan1";
    string m_topicNameForLidar2 = "/scan2";
    string m_topicNameForCamera = "/camera/depth/points";

    TFProcessor* pTFProcessor = nullptr;

public:
    ScanListener() = default;
    ~ScanListener() = default;

    const string& get_topic_name_for_lidar1() const {return m_topicNameForLidar1;}
    const string& get_topic_name_for_lidar2() const {return m_topicNameForLidar2;}
    const string& get_topic_name_for_camera() const {return m_topicNameForCamera;}
    
    void set_topic_name_for_lidar1(const string& topicName) {m_topicNameForLidar1 = topicName;}
    void set_topic_name_for_lidar2(const string& topicName) {m_topicNameForLidar2 = topicName;}
    void set_topic_name_for_camera(const string& topicName) {m_topicNameForCamera = topicName;}

    void enlist_tf_processor(TFProcessor& TFProcessor) {pTFProcessor = &TFProcessor;}

    void scan_callback_for_lidar1(const sensor_msgs::LaserScan::ConstPtr& msg);
    void scan_callback_for_lidar2(const sensor_msgs::LaserScan::ConstPtr& msg);
    void scan_callback_for_camera(const sensor_msgs::PointCloud2::ConstPtr& msg);
};