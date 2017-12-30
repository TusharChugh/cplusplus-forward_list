cmake_minimum_required(VERSION 3.2.2)
project(forward_tlist)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
add_subdirectory(src)
target_link_libraries(forward_tlist)

#add_subdirectory(test)