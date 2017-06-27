# Copyright: (C) 2017 Social Robotics Lab - Yale University
# Authors: Alessandro Roncone
# CopyPolicy: Released under the terms of the GNU GPL v2.1.

cmake_minimum_required(VERSION 2.8.3)
project(task-models)

SET(CMAKE_CXX_FLAGS "-std=gnu++14 -std=c++14 -std=gnu++1y -std=c++1y -std=gnu++11 -std=c++11 -std=gnu++0x -std=c++0x")

ADD_DEFINITIONS ( -Wall -Wextra -Wno-unused-parameter -Werror)

include_directories(lib/task-models/include)

## Add C++ libraries
add_subdirectory(lib)

# add_executable(htm-model  src/htm/main.cpp)

# target_link_libraries(htm-model task-models-lib)

## Add GTest tests
add_subdirectory(test)
