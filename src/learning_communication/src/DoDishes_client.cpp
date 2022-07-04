#include "ros/ros.h"
#include <actionlib/client/service_client.h>
#include "learning_communication/DoDishesAction.h"
typedef actionlib::SimpleActionClient<learning_communication::DoDishesAction> Client;
void doneCb(const actionlib::SimpleClientGoalState& state,
            const learning_communication::DoDishesResultConstPtr& result)
            {
                ROS_INFO("Yah! The dishes are now clean");
                ros::shutdown();
            }
void activeCb(){
    ROS_INFO("Goal just went active");
}

void feedbackCb(const learning_communication::DoDishesFeedbackConstPtr& feedback){
    ROS_INFO("percent_complete:%f",feedback->percent_complete);
}

int main(int argc, char** argv){
    ros::init(argc,argv,"do_dishes_client");

    Client client("do_dishes_client");

    ROS_INFO("Waiting for action server to start.");
    client.waitForServer();
    ROS_INFO("Action server started, sending goal.");

    learning_communication::DoDishesGoal goal;
    goal.dishwasher_id=1;

    client.sendGoal(goal,&doneCb,&activeCb,&feedbackCb);

    ros::spin();

    return 0;
}