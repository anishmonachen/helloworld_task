#include "ros/ros.h"
#include "std_msgs/String.h"
#include "saas_tutorial/OurMsg.h"

#include <sstream>


int main(int argc, char **argv)
{
  ros::init(argc, argv, "publisher");
  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::Publisher our_pub = n.advertise<saas_tutorial::OurMsg>("our_topic", 1000);

  ros::Rate loop_rate(25);

  int count = 0;
  while (ros::ok())
  {
    std_msgs::String msg;
    saas_tutorial::OurMsg our_msg;

    std::stringstream ss;
    ss << "Hello world x " << count;
    msg.data = ss.str();

    our_msg.value = count * count;

    ROS_INFO("%s", msg.data.c_str());

    chatter_pub.publish(msg);
    our_pub.publish(our_msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}

