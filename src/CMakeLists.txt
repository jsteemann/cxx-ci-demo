
add_library(calculator STATIC Calculator.cpp Value.cpp)

install(TARGETS calculator DESTINATION lib)
    
add_executable(main main.cpp)
target_link_libraries(main calculator)
