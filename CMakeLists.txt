cmake_minimum_required(VERSION 3.0.2)
project(sort_visualizer LANGUAGES CXX)

if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
   message(SEND_ERROR "In-source builds are not allowed.")
endif("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")

include(ExternalProject)

set(ALLEGRO_DIR ${CMAKE_BINARY_DIR}/allegro5)
ExternalProject_Add( allegro5
    GIT_REPOSITORY https://github.com/liballeg/allegro5.git
    GIT_TAG 5.2.3.0
    SOURCE_DIR ${ALLEGRO_DIR}
    BINARY_DIR ${ALLEGRO_DIR}
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${ALLEGRO_DIR}/install
    BUILD_COMMAND make
)
add_library(allegro SHARED IMPORTED)
link_directories(${ALLEGRO_DIR}/install/lib)
set_target_properties(allegro PROPERTIES
    IMPORTED_LOCATION ${ALLEGRO_DIR}/install/lib/liballegro.dylib
    INTERFACE_INCLUDE_DIRECTORIES ${ALLEGRO_DIR}/install/include
    IMPORTED_LINK_INTERFACE_LIBRARIES ${ALLEGRO_DIR}/install/lib/liballegro_main.dylib)

add_executable(app src/main.cpp)
add_dependencies(app allegro5)
target_link_libraries(app allegro)
