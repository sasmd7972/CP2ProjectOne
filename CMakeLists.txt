cmake_minimum_required(VERSION 3.17)
project(Project_One)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project_One main.cpp Vehicle.cpp Player.cpp Sedan.cpp Sedan.h Pickup.cpp Pickup.h Compact.cpp Compact.h Vehicle_AND_Player.h)