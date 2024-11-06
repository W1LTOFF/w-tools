cmake_minimum_required(VERSION 3.30)

project(examples)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23 -Wall -w")

link_libraries(
    w-tools
)

add_executable(main main.cpp)
