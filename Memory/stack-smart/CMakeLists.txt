cmake_minimum_required(VERSION 3.28)
project(stack_smart)

set(CMAKE_CXX_STANDARD 17)

add_executable(stack_smart main.cpp
        CharStack.cpp
        CharStack.h)
