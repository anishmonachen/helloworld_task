cmake_minimum_required(VERSION 2.8.3)
project(saas_tutorial)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  joy
  roscpp
  sensor_msgs
  std_msgs
  message_generation
)

################################################
## Declare ROS messages, services and actions ##
################################################

## Generate messages in the 'msg' folder
add_message_files(FILES OurMsg.msg)

## Generate services in the 'srv' folder
add_service_files(FILES StartStop.srv)

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
generate_messages(DEPENDENCIES geometry_msgs sensor_msgs std_msgs)

###################################
## catkin specific configuration ##
###################################
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES saas_tutorial
  CATKIN_DEPENDS geometry_msgs joy roscpp sensor_msgs std_msgs
  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(${catkin_INCLUDE_DIRS})

## Declare a cpp library
# add_library(saas_tutorial
#   src/${PROJECT_NAME}/saas_tutorial.cpp
# )

add_executable(publisher src/publisher.cpp)
add_dependencies(publisher saas_tutorial_generate_messages_cpp)
target_link_libraries(publisher ${catkin_LIBRARIES})

add_executable(subscriber src/subscriber.cpp)
add_dependencies(subscriber saas_tutorial_generate_messages_cpp)
target_link_libraries(subscriber ${catkin_LIBRARIES})


