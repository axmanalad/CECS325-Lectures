cmake_minimum_required(VERSION 3.28)
project(TargetGame)

set(CMAKE_CXX_STANDARD 20)

# This is where we list the .h (header) and .cpp (source) files in our program.
add_executable(Main
        main.cpp targetgame.cpp
        targetgame.h)
