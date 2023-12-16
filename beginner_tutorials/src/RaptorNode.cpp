#include "beginner_tutorials/RaptorNode.h"
#include <sstream>

RaptorNode::RaptorNode() {
    ros::NodeHandle n;
    pub = n.advertise<std_msgs::String>("RaptorOUT", 1000);
    sub = n.subscribe("RaptorIN", 1000, &RaptorNode::chatterCallback, this);
}

void RaptorNode::chatterCallback(const std_msgs::String::ConstPtr& msg) {
    std::string newMsgData = "{ <JakubWitczak>: <" + msg->data + "  / " + getTimestamp() + ">";
    std_msgs::String newMsg;
    newMsg.data = newMsgData;
    pub.publish(newMsg);
}

std::string RaptorNode::getTimestamp() {
    ros::Time currtime = ros::Time::now();
    std::ostringstream stime;
    stime << currtime;
    return stime.str();
}



