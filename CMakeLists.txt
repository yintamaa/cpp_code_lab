#cmake_minimum_required(VERSION 3.22)
project(cppTest)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)
add_executable(cppTest
        main.cpp "basic components/memory_pool/memory_pool.h" "practice sample/smart_pointer.h" "practice sample/override.h" "practice sample/static.h")
