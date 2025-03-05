cmake_minimum_required(VERSION 3.28)
project(statics)

set(CMAKE_CXX_STANDARD 17)

add_executable(statics main.cpp
        Student.cpp
        Student.h)
