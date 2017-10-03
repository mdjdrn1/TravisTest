cmake_minimum_required(VERSION 3.8)
project(TravisTest)

set(CMAKE_CXX_STANDARD 17)

set(CXX_FLAGS "-Wall -Weffc++ -m64 -O3")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS}")

add_executable(TravisTest src/main.cpp)

##############################################################################
# Setup the `check` target to build and then run all the tests
##############################################################################
add_custom_target(check
        COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
        WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
        COMMENT "Build and then run all the tests and examples.")

add_subdirectory(test)