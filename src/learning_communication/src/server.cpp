/**
 * @file server.cpp
 * @author your name (you@domain.com)
 * @brief AddTwoInts Server
 * @version 0.1
 * @date 2022-06-26
 * @copyright Copyright (c) 2022
 */

#include "ros/ros.h"
#include "learning_communication/AddTwoInts.h"

bool add(learning_communication::AddTwoInts::Request &req,
         learning_communication::AddTwoInts::Response &res)
         {
             res.sum=req.a+req.b;
             ROS_INFO("request: x=%ld, y=%ld",(long int)req.a,(long int)req.b);
             ROS_INFO("sending back response:[%ld]",(long int)res.sum);
             return true;
         }
int main(int argc,char **argv){
    //initialize ros node
    ros::init(argc,argv,"add_two_ints_server");

    //create NodeHandle
    ros::NodeHandle n;

    //Create a server named as "add_two_ints_server", call back function add()
    ros::ServiceServer service=n.advertiseService("add_two_ints",add);

    //loop wait call back function
    ROS_INFO("Ready to add ints.");
    ros::spin();

    return 0;
}