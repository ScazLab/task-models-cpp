# Copyright: (C) 2017 Social Robotics Lab - Yale University
# Authors: Alessandro Roncone
# CopyPolicy: Released under the terms of the GNU GPL v2.1.

cmake_minimum_required(VERSION 2.8.3)
project(task-models)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}")

## Find Eigen3
find_package(Eigen3 REQUIRED)
include_directories(SYSTEM ${EIGEN3_INCLUDE_DIR})

## Add C++11 and C++14 support
SET(CMAKE_CXX_FLAGS "-std=gnu++14 -std=c++14 -std=gnu++1y -std=c++1y -std=gnu++11 -std=c++11 -std=gnu++0x -std=c++0x")

## Add additional warning flags, as treat warnings as errors
ADD_DEFINITIONS ( -Wall -Wextra -Wno-unused-parameter -Werror)

## Add C++ libraries
add_subdirectory(lib)
include_directories(${ExampleLib_SOURCE_DIR})

## Add C++ executables
add_executable(example-main  src/example_main.cpp)
target_link_libraries(example-main example-lib)

## Add C++ tests using GTest
add_subdirectory(test)
