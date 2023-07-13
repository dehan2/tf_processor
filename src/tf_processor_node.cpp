#include "TFProcessor.h"
#include "ScanListener.h"

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <sensor_msgs/PointCloud2.h>

#include <string>
#include <functional>

using namespace std;

int main(int argc, char** argv)
{
    ros::init(argc, argv, "tf_processor_node");
    ros::NodeHandle nh;

    ScanListener scan_listener;
    TFProcessor tf_processor;
    scan_listener.enlist_tf_processor(tf_processor);

    ros::Subscriber subscriberForLidar1 = nh.subscribe("/scan1", 1000, &ScanListener::scan_callback_for_lidar1, &scan_listener);
    ros::Subscriber subscriberForLidar2 = nh.subscribe("/scan2", 1000, &ScanListener::scan_callback_for_lidar2, &scan_listener);
    ros::Subscriber subscriberForCamera = nh.subscribe("/camera/depth/points", 1000, &ScanListener::scan_callback_for_camera, &scan_listener);

    ros::Publisher publisherForLidar1 = nh.advertise<sensor_msgs::LaserScan>("/tf_scan1", 1000);
    ros::Publisher publisherForLidar2 = nh.advertise<sensor_msgs::LaserScan>("/tf_scan2", 1000);
    ros::Publisher publisherForCamera = nh.advertise<sensor_msgs::PointCloud2>("/tf_camera", 1000);

    tf_processor.enlist_publisher_for_lidar1(publisherForLidar1);
    tf_processor.enlist_publisher_for_lidar2(publisherForLidar2);
    tf_processor.enlist_publisher_for_camera(publisherForCamera);

    ros::spin();

    return 0;
}