cmake_minimum_required(VERSION 3.28)
project(card_class)

set(CMAKE_CXX_STANDARD 17)

add_executable(card_class main.cpp
        Card.cpp
        Card.h)
