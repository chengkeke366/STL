cmake_minimum_required(VERSION 3.20)
project(STL)

set(CMAKE_CXX_STANDARD 17)

add_executable(STL main.cpp RefCounter.cpp RefCounter.h)
