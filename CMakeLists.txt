cmake_minimum_required(VERSION 2.8.3)
project(ros_intro)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  actionlib
  actionlib_msgs
  roscpp
  std_msgs
  message_generation
)

catkin_package()

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
	include
  ${catkin_INCLUDE_DIRS}
)

add_executable(demo_topic_publisher src/demo_topic_publisher.cpp)
add_dependencies(demo_topic_publisher ros_intro_generate_messages_cpp)
target_link_libraries(demo_topic_publisher ${catkin_LIBRARIES})