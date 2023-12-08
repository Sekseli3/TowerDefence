cmake_minimum_required(VERSION 3.16)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)


include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)
add_executable(CMakeSFMLProject
    src/main.cpp 
    src/Objects/tower.cpp
    src/Objects/enemies.cpp
    src/Objects/EnemyTypeA.cpp 
    src/Objects/EnemyTypeB.cpp
    src/Objects/EnemyTypeC.cpp
    ) 
target_link_libraries(CMakeSFMLProject PRIVATE sfml-graphics)
target_compile_features(CMakeSFMLProject PRIVATE cxx_std_17)


install(TARGETS CMakeSFMLProject)