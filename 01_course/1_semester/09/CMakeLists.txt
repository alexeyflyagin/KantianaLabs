cmake_minimum_required(VERSION 3.30)

set(PROJECT_NAME example)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTANSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})