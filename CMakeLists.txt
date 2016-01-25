cmake_minimum_required(VERSION 2.6)

project(cxx-ci-demo)

set(CMAKE_BINARY_DIR "${CMAKE_SOURCE_DIR}/build")
  
message(STATUS "Build mode: ${CMAKE_BUILD_TYPE}")
message(STATUS "Install base directory: ${CMAKE_INSTALL_PREFIX}")
  
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra")

include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(Threads)

add_subdirectory(src)
add_subdirectory(include)

