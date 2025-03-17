cmake_minimum_required(VERSION 3.28)
project(stack_leakless)

set(CMAKE_CXX_STANDARD 17)

add_executable(stack_leakless main.cpp
        CharStack.cpp)
