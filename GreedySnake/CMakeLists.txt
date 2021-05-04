cmake_minimum_required(VERSION 3.17)
project(GreedySnake)

set(CMAKE_CXX_STANDARD 11)

add_executable(GreedySnake main.cpp controller.h controller.cpp food.h food.cpp map.cpp map.h point.h point.cpp snake.h snake.cpp startinterface.h startinterface.cpp tools.h tools.cpp)