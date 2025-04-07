cmake_minimum_required(VERSION 3.28)
project(string_linked_queue)

set(CMAKE_CXX_STANDARD 17)

add_executable(string_linked_queue main.cpp
        StringLinkedQueue.cpp
        StringLinkedQueue.h)
