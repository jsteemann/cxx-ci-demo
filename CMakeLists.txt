cmake_minimum_required(VERSION 2.6)

project(cxx-ci-demo)

set(CMAKE_BINARY_DIR "${CMAKE_SOURCE_DIR}/build")
  
message(STATUS "Build mode: ${CMAKE_BUILD_TYPE}")
message(STATUS "Install base directory: ${CMAKE_INSTALL_PREFIX}")

set(CMAKE_CXX_STANDARD 11)

option(Coverage "Build with coverage" OFF)
if(Coverage)
  set(CMAKE_BUILD_TYPE Debug)
endif()
  
if(CMAKE_COMPILER_IS_GNUCXX)
  # g++
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -Wall -Wextra")
  if(Coverage)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
  endif()
elseif(CMAKE_COMPILER_IS_CLANGCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  # clang
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -Wall -Wextra")
elseif(MSVC) 
  # visual studio
  foreach (flag_var
           CMAKE_CXX_FLAGS
           CMAKE_CXX_FLAGS_DEBUG
           CMAKE_CXX_FLAGS_RELEASE
           CMAKE_CXX_FLAGS_MINSIZEREL
           CMAKE_CXX_FLAGS_RELWITHDEBINFO)
    if (flag_var MATCHES "DEBUG")
      set(${flag_var} "${${flag_var}} /MTd")
    else ()
      set(${flag_var} "${${flag_var}} /MT")
    endif ()
  endforeach()

  # https://msdn.microsoft.com/en-us/library/aa267384%28VS.60%29.aspx
  set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} /INCREMENTAL:NO /SUBSYSTEM:CONSOLE /LTCG /ignore:4099 /NODEFAULTLIB:libc.lib /NODEFAULTLIB:libcmt.lib /NODEFAULTLIB:msvcrt.lib /NODEFAULTLIB:libcd.lib /NODEFAULTLIB:msvcrtd.lib")
  set(CMAKE_EXE_LINKER_FLAGS_MINSIZEREL "${CMAKE_EXE_LINKER_FLAGS_MINSIZEREL} /SUBSYSTEM:CONSOLE /ignore:4099 /NODEFAULTLIB:libc.lib /NODEFAULTLIB:libcmtd.lib /NODEFAULTLIB:msvcrt.lib /NODEFAULTLIB:libcd.lib /NODEFAULTLIB:msvcrtd.lib")
  set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /SUBSYSTEM:CONSOLE /ignore:4099 /NODEFAULTLIB:libc.lib /NODEFAULTLIB:libcmtd.lib /NODEFAULTLIB:msvcrt.lib /NODEFAULTLIB:libcd.lib /NODEFAULTLIB:msvcrtd.lib")
  set(CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO "${CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO} /SUBSYSTEM:CONSOLE /ignore:4099 /NODEFAULTLIB:libc.lib /NODEFAULTLIB:libcmtd.lib /NODEFAULTLIB:msvcrt.lib /NODEFAULTLIB:libcd.lib /NODEFAULTLIB:msvcrtd.lib")
else()
  # unknown compiler... try g++ values
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -Wall -Wextra")
endif()

include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(Threads)

add_subdirectory(src)
add_subdirectory(include)

# build tests
add_subdirectory(tests)

