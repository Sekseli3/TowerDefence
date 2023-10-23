cmake_minimum_required(VERSION 3.11.0)

project(Project VERSION 0.1.0)
include_directories("src")
file(GLOB SOURCES src/*.cpp)
add_executable(executable ${SOURCES})
