#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char** argv){
    //initize ros node
    ros::init(argc,argv,"talker");

    //create ros nodeHandle
    //the function of Nodehandle is to manage the ros node
    ros::NodeHandle n;

    //create a publisher, named as "chatter", its message form is std_msgs::String
    ros::Publisher chatter_pub=n.advertise<std_msgs::String>("chatter",1000);

    //set loop rate
    ros::Rate loop_rate(10);

    int count=0;
    while(ros::ok()){
        //initlize message as std_msgs::String
        std_msgs::String msg;
        std::stringstream ss;
        ss<<"hello world"<<count;
        msg.data=ss.str();

        //publish message
        ROS_INFO("%s",msg.data.c_str());
        chatter_pub.publish(msg);

        //loop wait recall function
        ros::spinOnce();

        //wait for frequency
        loop_rate.sleep();
        count++;
    }
    return 0;
}