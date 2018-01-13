cmake_minimum_required(VERSION 3.2)
project(forward_tlist)

#set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES forward_tlist/forward_tlist.cpp)
add_library(forward_tlist STATIC ${SOURCE_FILES})