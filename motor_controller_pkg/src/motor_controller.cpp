/*
This C++ file is a ROS subscriber node responsible for accessing and outputting data based off of the ROS topic 'motor_commands'.
*/ 
#include <ros/ros.h>				// necessary header file for ROS functionality 
#include <motor_controller_pkg/MotorCommand.h>	// include the custom message header for motor commands

// function to check for check the message from ROS topic (using a smart pointer 'msg' defined by ROS)
void motorCallback(const motor_controller_pkg::MotorCommand::ConstPtr& msg) {
	// if pointing to 'start', print 'Motor started'
	if (msg->command == "start") {
		ROS_INFO("Motor started");
	// if pointing to 'stop', print 'Motor stopped'
	} else if (msg->command == "stop") {
		ROS_INFO("Motor stopped");
	// if pointing to 'velocity', print the float value
	} else if (msg->command == "velocity") {
		ROS_INFO("Velocity set to %f", msg->velocity);
	}
}
// main function ran
int main(int argc, char** argv) {
    ros::init(argc, argv, "motor_controller");	// initialize ROS system with motor_controller node
    ros::NodeHandle nh;				// initialize NodeHanlde object

    ros::Subscriber sub = nh.subscribe("/motor_commands", 10, motorCallback);	// create subscriber object 'sub' to subscribe to messages published on topic '/motor_commands'

    ros::spin();	// allow main to loop continously

    return 0;
}

