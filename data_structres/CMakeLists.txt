cmake_minimum_required(VERSION 3.22)

project(CppProjectTemplate
    VERSION 1.0.0
    LANGUAGES C CXX)
 
set(EXECUTABLE_NAME main)
set(LIBRARY_NAME Library)


option(ENABLE_EXAMPLES "to enable examples" ON)

add_subdirectory(src)
add_subdirectory(inc)
add_subdirectory(app)

if(ENABLE_EXAMPLES)
    set(EXAMPLE_PARANTHESIS stack_paranthesis_matching)
    add_subdirectory(examples)
endif()
