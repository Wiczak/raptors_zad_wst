#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

class RaptorNode{
	public:
		RaptorNode()
		{
			ros::NodeHandle n;
			pub = n.advertise<std_msgs::String>("RaptorOUT", 1000);
			sub = n.subscribe("RaptorIN", 1000, &RaptorNode::chatterCallback,this);
		}
		void chatterCallback(const std_msgs::String::ConstPtr& msg)
		{
			
  			std::string newMsgData ="{ <JakubWitczak>: <"+ msg->data +"  / " + getTimestamp()+">";
  			std_msgs::String newMsg;
  			newMsg.data = newMsgData;
  			pub.publish(newMsg);
  		}
		std::string getTimestamp()
		{
			/*time_t now = time(0);
			tm* timeinfo = localtime(&now);
			char timestamp[80];
			strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);*/
			ros::Time currtime = ros::Time::now();
			std::ostringstream stime;
			stime << currtime;
			return stime.str();
		}
	private:
		ros::Subscriber sub;
		ros::Publisher pub;
};



int main(int argc, char **argv)
{

  ros::init(argc, argv, "raptor");

  RaptorNode raptorNode;
  
  
  ros::spin();
  
  return 0;
}



