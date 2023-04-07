cmake_minimum_required(VERSION 3.10)

project(DataPatternsMatcher)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BUILD_TYPE Debug)

set( CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage" )
set (CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage" )

include_directories(.)

add_subdirectory(code)
add_subdirectory(googletest-main)