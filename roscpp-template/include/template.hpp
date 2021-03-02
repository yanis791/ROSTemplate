#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include "std_msgs/String.h"

namespace ns_template {

class TemplateHandle {

 public:

  // Constructor
  TemplateHandle(ros::NodeHandle &nodeHandle);

  // Methods
  void loadParameters();
  void subscribeToTopics();
  void publishToTopics();
  void run();
  void sendMsg();
  void runAlgorithm();

  ros::NodeHandle nodeHandle;

  // Getters
  int getNodeRate() const;
  int node_rate;
};

 
}
  


  


#endif //TEMPLATE_HPP
