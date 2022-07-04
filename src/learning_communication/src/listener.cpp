/**
 * @file listener.cpp
 * @author your name (you@domain.com)
 * @brief to accomplish a topic "chatter", its type is String
 * @version 0.1
 * @date 2022-06-25
 * @copyright Copyright (c) 2022
 */

#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"

//recall function
void chatterCallBack(const std_msgs::String::ConstPtr msg){
    //print receieved information
    ROS_INFO("I heard:[%s]",msg->data.c_str());
}

int main(int argc, char** argv){
    //initialize ROS node
    ros::init(argc,argv,"listener");

    //create NodeHandle
    ros::NodeHandle n;

    //create a subscriber, named as chatter, the recall function is "chatterCallback"
    ros::Subscriber sub=n.subscribe("chatter",1000,chatterCallBack);

    //wait for callback function
    ros::spin();

    return 0;
}