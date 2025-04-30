cmake_minimum_required(VERSION 3.28)
project(string_queue_smart)

set(CMAKE_CXX_STANDARD 17)

add_executable(string_queue_smart main.cpp
        StringLinkedQueue.cpp
        StringLinkedQueue.h)
