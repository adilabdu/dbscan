cmake_minimum_required(VERSION 3.10)

set (CMAKE_CXX_STANDARD 11)

# set the project name
project(dbscan)

# add the executable
add_executable(dbscan main.cpp dbscan.cpp)