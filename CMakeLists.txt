cmake_minimum_required (VERSION 2.8)
project (Examples)

set (CMAKE_CXX_FLAGS "--std=c++11 ${CMAKE_CXX_FLAGS}")

add_subdirectory (advance)
add_subdirectory (DynStructures)
add_subdirectory (Hello)
add_subdirectory (oop)
add_subdirectory (Shapes)
add_subdirectory (templates)
