cmake_minimum_required(VERSION 2.6)

project(cxx-ci-demo)

set(CMAKE_BINARY_DIR "${CMAKE_SOURCE_DIR}/build")
  
message(STATUS "Build mode: ${CMAKE_BUILD_TYPE}")
message(STATUS "Install base directory: ${CMAKE_INSTALL_PREFIX}")

option(Coverage "Build with coverage" OFF)
if(Coverage)
  set(CMAKE_BUILD_TYPE Debug)
endif()
  
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -Wall -Wextra")
if(Coverage)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(Threads)

add_subdirectory(src)
add_subdirectory(include)

# build tests
add_subdirectory(tests)

