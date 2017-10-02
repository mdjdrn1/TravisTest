cmake_minimum_required(VERSION 3.8)
project(TravisTest)

set(CMAKE_CXX_STANDARD 17)

set(CXX_FLAGS "-Wall -Weffc++ -m64 -O3")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS}")

add_executable(TravisTest main.cpp)
