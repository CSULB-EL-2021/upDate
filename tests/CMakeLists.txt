set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS})

add_executable (unit_tests main.test.cpp basic.test.cpp operatorSimple.test.cpp operatorLogic.test.cpp ../upDate.cpp)

target_link_libraries (unit_tests ${Boost_LIBRARIES})

add_test(
    NAME all_tests
    COMMAND $<TARGET_FILE:unit_tests> --log_level=all
)
