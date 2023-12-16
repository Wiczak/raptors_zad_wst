#pragma once

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <string>

class RaptorNode {
public:
    RaptorNode();
    void chatterCallback(const std_msgs::String::ConstPtr& msg);
    std::string getTimestamp();

private:
    ros::Subscriber sub;
    ros::Publisher pub;
};
