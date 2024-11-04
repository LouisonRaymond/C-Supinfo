cmake_minimum_required(VERSION 3.27)
project(C_Supinfo)

set(CMAKE_CXX_STANDARD 14)

include_directories(Include)

add_executable(C_Supinfo
        Source/main.cpp)
