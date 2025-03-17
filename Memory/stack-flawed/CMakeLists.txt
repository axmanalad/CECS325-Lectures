cmake_minimum_required(VERSION 3.28)
project(stack_flawed)

set(CMAKE_CXX_STANDARD 17)

add_executable(stack_flawed main.cpp
        CharStack.cpp
        CharStack.h)
