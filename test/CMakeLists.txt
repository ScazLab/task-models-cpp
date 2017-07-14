# Copyright: (C) 2017 Social Robotics Lab - Yale University
# Authors: Alessandro Roncone <alessandro.roncone@yale.edu>
# CopyPolicy: Released under the terms of the GNU LGPL v2.1.

cmake_minimum_required(VERSION 2.8.3)
project(test-task-models)

## Gtest compilation has been taken from https://github.com/kaizouman/gtest-cmake-example
find_package(Threads REQUIRED)

# Enable Tests
include(CTest)

# Enable ExternalProject CMake module
include(ExternalProject)

# Download and install GoogleTest
ExternalProject_Add(
    gtest
    URL https://github.com/google/googletest/archive/master.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
    # Disable install step
    INSTALL_COMMAND ""
)

# Get GTest source and binary directories from CMake project
ExternalProject_Get_Property(gtest source_dir binary_dir)

# Create a libgtest target to be used as a dependency by test programs
add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest gtest)

# Set libgtest properties
set_target_properties(libgtest PROPERTIES
    "IMPORTED_LOCATION" "${binary_dir}/googlemock/gtest/libgtest.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

# Create a libgmock target to be used as a dependency by test programs
add_library(libgmock IMPORTED STATIC GLOBAL)
add_dependencies(libgmock gtest)

# Set libgmock properties
set_target_properties(libgmock PROPERTIES
    "IMPORTED_LOCATION" "${binary_dir}/googlemock/libgmock.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

# I couldn't make it work with INTERFACE_INCLUDE_DIRECTORIES
include_directories("${source_dir}/googletest/include"
                    "${source_dir}/googlemock/include")

# Add test cpp file
add_executable(testExampleClass     test_example_class.cpp)

# Added test
add_executable(testHierarchicalTask test_hierarchical_task.cpp)

# Link test executable against gtest & gtest_main
target_link_libraries(testExampleClass example-lib libgtest libgmock)

# Added link
target_link_libraries(testHierarchicalTask task-models libgtest libgmock)

add_test(NAME    testExampleClass
         COMMAND testExampleClass)

# Added test

add_test(NAME    testHierarchicalTask
         COMMAND testHierarchicalTask)
