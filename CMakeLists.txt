# Copyright: (C) 2017 Social Robotics Lab - Yale University
# Authors: Alessandro Roncone
# CopyPolicy: Released under the terms of the GNU GPL v2.1.

cmake_minimum_required(VERSION 2.8.3)
project(task-models)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}")

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

SET(CMAKE_CXX_FLAGS "-std=gnu++14 -std=c++14 -std=gnu++1y -std=c++1y -std=gnu++11 -std=c++11 -std=gnu++0x -std=c++0x")

ADD_DEFINITIONS ( -Wall -Wextra -Wno-unused-parameter -Werror)

include_directories(lib/task-models/include)

## Add C++ libraries
add_subdirectory(lib)

add_executable(example-main  src/example_main.cpp)
# target_link_libraries(example-main)

## Add GTest tests
add_subdirectory(test)
