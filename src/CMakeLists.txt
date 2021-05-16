cmake_minimum_required(VERSION 3.9)

project(myfuncs VERSION 1.0.1 DESCRIPTION "MyFunctions")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE CFILES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

add_library(mylib SHARED ${CFILES})
