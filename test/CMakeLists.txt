add_custom_target(tests COMMENT "Build all the unit tests.")
add_dependencies(check tests)

##############################################################################
# Add all the remaining unit tests
##############################################################################
file(GLOB_RECURSE UNIT_TESTS "*.cpp")
file(GLOB_RECURSE EXCLUDED_UNIT_TESTS ${EXCLUDED_UNIT_TESTS})
#list(REMOVE_ITEM UNIT_TESTS ${EXCLUDED_UNIT_TESTS})

foreach(_file IN LISTS UNIT_TESTS)
    boost_hana_target_name_for(_target "${_file}")
    add_executable(${_target} EXCLUDE_FROM_ALL "${_file}")
    boost_hana_set_test_properties(${_target})
    if (_file IN_LIST TESTS_REQUIRING_BOOST)
        target_link_libraries(${_target} PRIVATE Boost::boost)
    endif()
    target_include_directories(${_target} PRIVATE _include)
    add_test(${_target} "${CMAKE_CURRENT_BINARY_DIR}/${_target}")
    add_dependencies(tests ${_target})
endforeach()