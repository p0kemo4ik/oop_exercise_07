cmake_minimum_required(VERSION 3.12)
project(lab7)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab7 main.cpp editor.hpp editor.cpp figure.hpp vertex.hpp document.hpp document.cpp factory.hpp factory.cpp command.hpp command.cpp pentagon.hpp octagon.hpp hexagon.hpp pentagon.cpp octagon.cpp hexagon.cpp vertex.cpp)