cmake_minimum_required(VERSION 3.24)
project(Snake C)

set(CMAKE_C_STANDARD 23)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(Snake main.c src/snake.c src/snake.h src/food.c src/food.h src/global.h)
target_link_libraries(Snake ${SDL2_LIBRARIES})