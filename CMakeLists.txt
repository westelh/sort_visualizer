cmake_minimum_required(VERSION 3.0.2)
project(sort_visualizer LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Werror")

if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
   message(SEND_ERROR "In-source builds are not allowed.")
endif("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")

set(ALLEGRO_DIR ${CMAKE_BINARY_DIR}/allegro)
set(ALLEGRO_SUB_LIBS
	${ALLEGRO_DIR}/install/lib/liballegro_main.dylib
	${ALLEGRO_DIR}/install/lib/liballegro_primitives.dylib)
add_library(allegro SHARED IMPORTED)
link_directories(${ALLEGRO_DIR}/install/lib)
set_target_properties(allegro PROPERTIES
    IMPORTED_LOCATION ${ALLEGRO_DIR}/install/lib/liballegro.dylib
    INTERFACE_INCLUDE_DIRECTORIES ${ALLEGRO_DIR}/install/include
    IMPORTED_LINK_INTERFACE_LIBRARIES "${ALLEGRO_SUB_LIBS}")

file(GLOB SRCS src/*.cpp)
file(GLOB HEADERS headers/*.hpp)
add_executable(app ${SRCS} ${HEADERS})
add_dependencies(app allegro)
target_link_libraries(app allegro)
target_include_directories(app PRIVATE headers)
