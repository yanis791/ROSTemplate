#include <ros/ros.h>
#include "template.hpp"

typedef ns_template::TemplateHandle TemplateHandle;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "template");

  //  /node_namespace/node_name
  ros::NodeHandle nodeHandle("~");

  TemplateHandle myTemplateHandle(nodeHandle);
  
  ros::Rate loop_rate(myTemplateHandle.getNodeRate());
  
  while (ros::ok())
  {

    myTemplateHandle.run();
    myTemplateHandle.sendMsg();

    ros::spinOnce();   // Keeps node alive basically
    loop_rate.sleep(); // Sleep for loop_rate
  }
  return 0;
}

TemplateHandle::TemplateHandle(ros::NodeHandle &nodeHandle): nodeHandle(nodeHandle){
  loadParameters(); 
  subscribeToTopics();
  publishToTopics();
  };

int TemplateHandle::getNodeRate() const { return node_rate; }

// Methods
void TemplateHandle::loadParameters() {
   ROS_INFO("loading handle parameters");
  if (!nodeHandle.param("node_rate", node_rate, 1)) {
    ROS_WARN_STREAM("Did not load node_rate. Standard value is: " << node_rate);
  }
}

void TemplateHandle::subscribeToTopics() {
  ROS_INFO("subscribe to topics");
  //visionConeDetectionsSubscriber_ =
  //nodeHandle_.subscribe(vision_cone_detections_topic_name_, 1, &TemplateHandle::visionConeDetectionsCallback, this);
}

void TemplateHandle::publishToTopics() {
  ROS_INFO("publish to topics");
  //templateStatePublisher_ = nodeHandle_.advertise<fsd_common_msgs::ConeDetections>(template_state_topic_name_, 1);
}

void TemplateHandle::sendMsg() {
  //templateStatePublisher_.publish(template_.getConeDetections());
}