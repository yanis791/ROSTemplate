#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

namespace ns_template {

class Template {

 public:

  // Constructor
  Template(ros::NodeHandle &nodeHandle);

/*********************************************************
 * Getters
**********************************************************/
  int getNodeRate() const;

/*********************************************************
 * Methods
**********************************************************/
  void loadParameters();
  void subscribeToTopics();
  void publishToTopics();
  void run();
  void sendMsg();
  void runAlgorithm();
 
 private:
 
/*********************************************************
 * Variable
**********************************************************/
  ros::NodeHandle nodeHandle;
  int node_rate;

};

 
}
  


  


#endif //TEMPLATE_HPP
