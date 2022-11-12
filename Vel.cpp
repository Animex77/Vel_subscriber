#include <ros/ros.h>
// #include "std_msgs/String.h"
#include "turtlesim/Pose.h"


void VelCallback(const turtlesim::Pose::ConstPtr& msg)
{
  ROS_INFO("Vel: linear_velocity:%0.6f, angular_velocity:%0.6f", msg->linear_velocity,msg->angular_velocity);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "Vel_subscriber");
  
  ros::NodeHandle n;

  ros::Subscriber pose_sub = n.subscribe("turtlesim/Pose.h", 10, VelCallback);


  ros::spin();

  return 0;
}