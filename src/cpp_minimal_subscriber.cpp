/**
 * @file cpp_minimal_subscriber.cpp
 * @author binhthuan
 * @brief Demonstrates  subscribing to messages on a ROS 2 topic
 * @date May 01, 2026
 * 
 * -----------
 * Subscription Topics:
 *  String message
 *  /cpp_example_topic - std_msgs/String
 * -----------
 * Publishing Topics:
 *  None
 * 
 */

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"


class MinimalCppSubscriber : public rclcpp::Node
{
public:
  MinimalCppSubscriber() : Node("minimal_cpp_subscriber")
  {
    subscriber_ = create_subscription<std_msgs::msg::String>(
      "/cpp_example_topic",
      10,
      [this](std_msgs::msg::String::SharedPtr msg){
        RCLCPP_INFO_STREAM(this->get_logger(), "I heard: " <<msg->data);
      }
    );
  }
  
  // void topicCallback(const std_msgs::msg::String& msg) const
  // {
  //   RCLCPP_INFO_STREAM(get_logger(), "I heard: " << msg.data.c_str());
  // }

private:
  // Member variables
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_;

};

int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);
  auto minimal_cpp_subscriber_node = std::make_shared<MinimalCppSubscriber>();
  rclcpp::spin(minimal_cpp_subscriber_node);
  
  rclcpp::shutdown();

  return 0;
}