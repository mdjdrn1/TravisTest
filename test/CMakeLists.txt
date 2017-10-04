add_custom_target(tests COMMENT "Build all the unit tests.")

enable_testing()
set(PROJECT_TEST_NAME ${PROJECT_NAME_STR}_test)
include_directories("${CMAKE_SOURCE_DIR}/lib/googletest/googletest/include")
include_directories("${CMAKE_SOURCE_DIR}/lib/googletest/googletest/")

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
add_dependencies(check tests)

add_library(libgtest IMPORTED STATIC GLOBAL)

target_link_libraries(libgtest)
target_link_libraries(${PROJECT_TEST_NAME} ${CMAKE_THREAD_LIBS_INIT})
