cmake_minimum_required(VERSION 3.16)

project(firstProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(firstProject
    firstProject.cpp
    glad.c
)

target_include_directories(firstProject PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/glfw-3.5.1/include
)

target_link_libraries(firstProject PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/glfw-3.5.1/build/src/libglfw3.a
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
    "-framework QuartzCore"
)
