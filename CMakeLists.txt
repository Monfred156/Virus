cmake_minimum_required(VERSION 3.24)
project(Virus)

set(CMAKE_CXX_STANDARD 14)

include_directories(inc)

add_executable(Virus
        main.cpp
        src/Cube.cpp
        src/Vector3.cpp src/Container.cpp inc/Container.h)
