cmake_minimum_required(VERSION 3.28)
project(string_linked_queue_improved)

set(CMAKE_CXX_STANDARD 17)

add_executable(string_linked_queue_improved main.cpp
        StringLinkedQueue.cpp StringLinkedQueue.h)
