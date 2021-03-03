#include <ros/ros.h>
#include "template.hpp"

typedef ns_template::Template Template;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "template");

  //  /node_namespace/node_name
  ros::NodeHandle nodeHandle("~");

  Template myTemplate(nodeHandle);
  
  ros::Rate loop_rate(myTemplate.getNodeRate());
  
  while (ros::ok())
  {

    myTemplate.run();
    myTemplate.sendMsg();

    ros::spinOnce();   // Keeps node alive basically
    loop_rate.sleep(); // Sleep for loop_rate
  }
  return 0;
}

Template::Template(ros::NodeHandle &nodeHandle): nodeHandle(nodeHandle){
  loadParameters(); 
  subscribeToTopics();
  publishToTopics();
  };

int Template::getNodeRate() const { return node_rate; }

void Template::loadParameters() {
   ROS_INFO("loading handle parameters");

  /***
    if (!nodeHandle.param("parameters_name", 
                          parameters_name_var, 
                          standard_value)) 
    ROS_WARN_STREAM("Did not load parameters_name);
  ***/

  if (!nodeHandle.param("node_rate", node_rate, 1))
  ROS_WARN_STREAM("Did not load node_rate.");
}

void Template::subscribeToTopics() {
  ROS_INFO("subscribe to topics");

  //Subscriber = nodeHandle.subscribe(topic_name, 1, &Callback, this);

}

void Template::publishToTopics() {
  ROS_INFO("publish to topics");

  //Publisher = nodeHandle.advertise<msg_type>(topic_name_, 1);

}

void Template::sendMsg() {

  //Publisher.publish(msg);

}