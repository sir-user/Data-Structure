message("IN app CMakeLists")
add_executable(${EXECUTABLE_NAME} main.c)
target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${LIBRARY_NAME})
message("END OF IN app CMakeLists")