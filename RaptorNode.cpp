#include "RaptorNode.h"
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
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    char timestamp[80];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);
    return timestamp;
}



