#include "TFProcessor.h"


TFProcessor::TFProcessor() 
  : m_tfListener(m_tfBuffer)
{
  // Nothing to do here
}



void TFProcessor::publish_transformed_message_for_lidar1(const sensor_msgs::LaserScan::ConstPtr& msg)
{
  if(pTFPublisherForLidar1 != nullptr)
  {
    geometry_msgs::TransformStamped transformStamped;
    try
    {
      transformStamped = m_tfBuffer.lookupTransform("base_link", "lidar1_link", ros::Time(0));
    }
    catch (tf2::TransformException &ex) 
    {
      ROS_WARN("%s",ex.what());
      return;
    }

    sensor_msgs::LaserScan transformed_msg;
    transformed_msg = *msg;
    transformed_msg.header.seq = msg->header.seq;
    transformed_msg.header.frame_id = transformStamped.header.frame_id;
    transformed_msg.header.stamp = msg->header.stamp;

    pTFPublisherForLidar1->publish(transformed_msg);
  }
}



void TFProcessor::publish_transformed_message_for_lidar2(const sensor_msgs::LaserScan::ConstPtr& msg)
{
  if(pTFPublisherForLidar2 != nullptr)
  {
    geometry_msgs::TransformStamped transformStamped;
    try
    {
      transformStamped = m_tfBuffer.lookupTransform("base_link", "lidar2_link", ros::Time(0));
    }
    catch (tf2::TransformException &ex) 
    {
      ROS_WARN("%s",ex.what());
      return;
    }

    sensor_msgs::LaserScan transformed_msg;
    transformed_msg = *msg;
    transformed_msg.header.seq = msg->header.seq;
    transformed_msg.header.frame_id = transformStamped.header.frame_id;
    transformed_msg.header.stamp = msg->header.stamp;

    pTFPublisherForLidar2->publish(transformed_msg);
  }
}



void TFProcessor::publish_transformed_message_for_camera(const sensor_msgs::PointCloud2::ConstPtr& msg)
{
  if(pTFPublisherForCamera != nullptr)
  {
    geometry_msgs::TransformStamped transformStamped;
    try
    {
      transformStamped = m_tfBuffer.lookupTransform("base_link", "camera_link", ros::Time(0));
    }
    catch (tf2::TransformException &ex) 
    {
      ROS_WARN("%s",ex.what());
      return;
    }

    sensor_msgs::PointCloud2 transformed_msg;
    transformed_msg = *msg;
    transformed_msg.header.seq = msg->header.seq;
    transformed_msg.header.frame_id = transformStamped.header.frame_id;
    transformed_msg.header.stamp = msg->header.stamp;

    pTFPublisherForCamera->publish(transformed_msg);
  }
}