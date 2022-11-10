cmake_minimum_required(VERSION 3.22)
project(cppTest)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)
add_executable(cppTest
        main.cpp)
