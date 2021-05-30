cmake_minimum_required(VERSION 3.19)
project(matrix_sandbox)

set(CMAKE_CXX_STANDARD 14)

add_executable(matrix_sandbox main.cpp src/Matrix.cpp src/Matrix.h lib/json.hpp)