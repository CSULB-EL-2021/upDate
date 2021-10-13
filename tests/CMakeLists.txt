set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS})

add_executable (Tests_run basic.test.cpp operatorSimple.test.cpp ../upDate.cpp)

target_link_libraries (Tests_run ${Boost_LIBRARIES})
