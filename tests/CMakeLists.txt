
include(CTest)
enable_testing()

# build gtest
add_subdirectory(googletest/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# build test for add
add_executable(AddTest AddTest.cpp)
target_link_libraries(AddTest gtest calculator ${CMAKE_THREAD_LIBS_INIT})
add_test(AddTest AddTest)

# build test for divide
add_executable(DivideTest DivideTest.cpp)
target_link_libraries(DivideTest gtest calculator ${CMAKE_THREAD_LIBS_INIT})
add_test(DivideTest DivideTest)
    
