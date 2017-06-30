#include "ros/ros.h"
#include "std_msgs/String.h"
#include "saas_tutorial/OurMsg.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

void ourCallback(const saas_tutorial::OurMsg::ConstPtr& msg)
{
  ROS_INFO("I got: [%d].", msg->value);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "subscriber");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
  ros::Subscriber my_sub = n.subscribe("our_topic", 1000, ourCallback);

  ros::spin();

  return 0;
}
