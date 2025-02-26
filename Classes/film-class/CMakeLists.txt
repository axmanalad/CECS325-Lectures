cmake_minimum_required(VERSION 3.28)
project(film_class)

set(CMAKE_CXX_STANDARD 17)

add_executable(film_class main.cpp
        Film.cpp
        Film.h)
