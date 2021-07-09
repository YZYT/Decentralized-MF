cmake_minimum_required(VERSION 3.15)
project(RS)
# set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -march=native -O3 -mavx -mfma")
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -O3")
set(CMAKE_CXX_STANDARD 20)

include_directories(libs/eigen-3.3.9)
add_executable(RS main.cpp cmake-build-debug/Client.h Server.h Data.cpp Data.h Client.cpp Client.h base.h Server.cpp basic.cpp)