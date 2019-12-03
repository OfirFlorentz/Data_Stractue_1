cmake_minimum_required(VERSION 3.10.2)
project(hw1_wet)

set(CMAKE_CXX_STANDARD 14)

SET(GCC_COVERAGE_COMPILE_FLAGS "-g -std=c++11 -o DCM -Wall -pedantic-errors -Werror -Wreorder -DNDEBUG")


add_executable(hw1_wet main.cpp Queue.h DC.h DC.cpp Node.h Node.cpp DCM.cpp DCM.h libary1.cpp libary1.h)

