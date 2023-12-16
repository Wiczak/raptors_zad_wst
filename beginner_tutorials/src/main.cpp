#include "ros/ros.h"
#include "beginner_tutorials/RaptorNode.h"

int main(int argc, char** argv) {
    ros::init(argc, argv, "raptor");
    RaptorNode raptorNode;
    ros::spin();
    return 0;
}
