set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS})

add_executable (unit_tests main.test.cpp basic.test.cpp operatorSimple.test.cpp ../upDate.cpp)

target_link_libraries (unit_tests ${Boost_LIBRARIES})
