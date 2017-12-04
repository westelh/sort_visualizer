cmake_minimum_required(VERSION 3.0.2)
project(sort_visualizer LANGUAGES CXX)

if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
   message(SEND_ERROR "In-source builds are not allowed.")
endif("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")

include(ExternalProject)

ExternalProject_Add(
    allegro5
    GIT_REPOSITORY https://github.com/liballeg/allegro5.git
    GIT_TAG 5.2.3.0
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/allegro5
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/allegro5/install
    BINARY_DIR ${CMAKE_SOURCE_DIR}/allegro5
    BUILD_COMMAND make
)

add_executable(app src/main.cpp)
add_dependencies(app allegro5)
