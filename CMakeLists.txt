cmake_minimum_required(VERSION 3.20)
project(prog4)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp upDate.cpp upDate.h)
add_executable(prog4 ${SOURCE_FILES})

enable_testing()
add_subdirectory(tests)
