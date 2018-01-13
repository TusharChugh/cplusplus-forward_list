cmake_minimum_required(VERSION 3.2.2)
project(forward_tlist)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)
add_subdirectory(src)

target_link_libraries(forward_tlist)

add_subdirectory(test)