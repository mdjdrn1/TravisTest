cmake_minimum_required(VERSION 3.8)
project(TravisTest)

set(CMAKE_CXX_STANDARD 17)

set(CXX_FLAGS "-Wall -m64 -O3")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS} ${BOOST_FLAGS}")

add_executable(TravisTest src/main.cpp)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.65 COMPONENTS system filesystem)

if (NOT Boost_FOUND)
    message(WARNING "The rest of Boost was not found; some tests and examples will be disabled.")
else()
    include_directories(${Boost_INCLUDE_DIR})
    link_directories(${Boost_LIBRARY_DIRS})
    target_link_libraries(TravisTest ${Boost_LIBRARIES})
endif()

##############################################################################
# Setup the `check` target to build and then run all the tests
##############################################################################
add_custom_target(check
        COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
        WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
        COMMENT "Build and then run all the tests and examples.")

enable_testing()
find_program(MEMORYCHECK_COMMAND valgrind)
if (MEMORYCHECK_COMMAND)
    message(STATUS "Found Valgrind: ${MEMORYCHECK_COMMAND}")
    set(MEMORYCHECK_COMMAND_OPTIONS "--leak-check=full --error-exitcode=1")
else()
    message("Valgrind not found")
endif()
include(CTest)

add_subdirectory(test)