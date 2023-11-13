cmake_minimum_required(VERSION 3.5)
project(tower_defence)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "")
set(EXECUTABLE_OUTPUT_PATH ../build)


add_executable(
        tower_defence

        src/main.cpp
)

target_link_libraries(tower_defence sfml-graphics sfml-window sfml-system)