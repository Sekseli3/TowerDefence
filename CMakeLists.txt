cmake_minimum_required(VERSION 3.16)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
configure_file(${CMAKE_SOURCE_DIR}/FreeMono.ttf ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/FreeMono.ttf COPYONLY)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# Group source files together
set(SOURCE_FILES
    src/main.cpp 
    src/Objects/tower.cpp
    src/Objects/enemies.cpp
    src/Objects/EnemyTypeA.cpp 
    src/Objects/EnemyTypeB.cpp
    src/Objects/EnemyTypeC.cpp
)

add_executable(CMakeSFMLProject ${SOURCE_FILES})

# Specify the C++ standard
target_compile_features(CMakeSFMLProject PRIVATE cxx_std_17)

# Link SFML libraries
target_link_libraries(CMakeSFMLProject PRIVATE sfml-graphics)

# Specify include directories
target_include_directories(CMakeSFMLProject PRIVATE ${CMAKE_SOURCE_DIR}/src)

install(TARGETS CMakeSFMLProject)