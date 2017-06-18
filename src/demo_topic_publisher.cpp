/**
 * Publish integers from 0 onwards to "numbers" topic at 10 Hz
 **/


//// Standard headers ////
#include <iostream>

//// ROS headers ////
// Main client APIs header
#include "ros/ros.h"
// Message header for standard message of Int32 type
#include "std_msgs/Int32.h"

int main(int argc, char **argv)
{
	// Initialize ROS. 3rd argument is the name of the node.
	ros::init(argc, argv, "demo_topic_publisher");
	
	// Get a handle to the node. All access to the node is through this handle.
	ros::NodeHandle node;
	
	// Tell the master node that we are going to be publishing a message of type Int32 on the topic
	// "numbers". The second argument is the queue size. If we are publishing messages more quickly
	// than we are able to send them, 100 messages are buffered at one time.
	ros::Publisher number_publisher = node.advertise<std_msgs::Int32>("numbers", 100);

	// Used to maintain the frequency specified as the argument
	ros::Rate loop_rate(10);

	// Message contents
	int count = 0;
	while(ros::ok())
	{
		std_msgs::Int32 msg;
		msg.data = count;
		count++;

		// Log the message published
		ROS_INFO("Publishing: %d", msg.data);

		number_publisher.publish(msg);

		// Used to run the main thread again so that callbacks get called. As we are using this
		// inside a loop we use ros::spinOnce(). Outside of loops ros::spin() is used.
		ros::spinOnce();

		// Sleep for the appropriate amount of time so as to maintain 10 Hz publishing rate
		loop_rate.sleep();
	}
	return 0;
}