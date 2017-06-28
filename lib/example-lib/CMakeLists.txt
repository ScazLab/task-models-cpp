# Copyright: (C) 2016 Social Robotics Lab - Yale University
# Authors: Alessandro Roncone
# CopyPolicy: Released under the terms of the LGPLv2.1.

cmake_minimum_required(VERSION 2.8.3)

add_library(example-lib include/example-lib/exampleClass.h     src/exampleClass.cpp)

# Define headers for this library. PUBLIC headers are used for
# compiling the library, and will be added to consumers' build
# paths.
target_include_directories(example-lib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src)

# target_link_libraries(example-lib)
