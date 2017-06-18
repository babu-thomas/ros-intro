/**
 * Subscribe to "numbers" topic and log the messages received
 **/

#include <iostream>

#include "ros/ros.h"
#include "std_msgs/Int32.h"

// Callback function that will get called every time we receive a message of "numbers" topic
void number_callback(const std_msgs::Int32::ConstPtr& msg)
{
	ROS_INFO("Received: %d", msg->data);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "demo_topic_subscriber");
	ros::NodeHandle node;

	// Subscribe to "numbers" topic with queue size 10. The third argument is the callback function
	// which is called every time a message is received.
	ros::Subscriber number_subscriber = node.subscribe("numbers", 10, number_callback);

	// As we are outside of any loops we call ros::spin() instead of ros::spinOnce()
	ros::spin();
	
	return 0;
}