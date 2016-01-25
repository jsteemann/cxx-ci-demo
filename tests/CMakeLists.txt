
include(CTest)
enable_testing()

# build gtest
add_subdirectory(googletest/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# build test
add_executable(CalculatorTest CalculatorTest.cpp)
target_link_libraries(CalculatorTest gtest calculator ${CMAKE_THREAD_LIBS_INIT})
