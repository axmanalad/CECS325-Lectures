cmake_minimum_required(VERSION 3.28)
project(stack_leaky)

set(CMAKE_CXX_STANDARD 17)

add_executable(stack_leaky main.cpp
        CharStack.cpp)
