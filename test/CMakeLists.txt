cmake_minimum_required(VERSION 3.2)
project(forward_tlist_Test)

#set(CMAKE_CXX_STANDARD 1y)
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()

set(SOURCE_FILES forward_tlist/unit_tests.cpp forward_tlist/forward_tlist_constructor_test.cpp forward_tlist/forward_tlist_iterator_test.cpp)

add_executable(unittest_forward_tlist ${SOURCE_FILES})
target_link_libraries(unittest_forward_tlist ${GTEST_LIBRARIES} forward_tlist pthread)