cmake_minimum_required(VERSION 3.28)
project(complex)

set(CMAKE_CXX_STANDARD 20)

add_executable(complex main.cpp
        Complex.cpp
        Complex.h)
