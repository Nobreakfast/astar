cmake_minimum_required(VERSION 3.13)
project(astar)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(astar main.cpp node.cpp node.h)

