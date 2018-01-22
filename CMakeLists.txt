cmake_minimum_required(VERSION 3.0.2)
project(sort_visualizer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Werror -g3 -O0")

set(ALLEGRO_DIR "${CMAKE_BINARY_DIR}/allegro-5.0.10-mingw-4.5.0")

if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
   message(SEND_ERROR "In-source builds are not allowed.")
endif("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")

if(UNIX)
	set(ALLEGRO_DIR ${CMAKE_BINARY_DIR}/allegro/install)
	set(ALLEGRO_LIB_DIR ${ALLEGRO_DIR}/lib)
	set(ALLEGRO_LIB ${ALLEGRO_LIB_DIR}/liballegro.dylib)
	set(ALLEGRO_SUB_LIBS
		${ALLEGRO_LIB_DIR}/liballegro_main.dylib
		${ALLEGRO_LIB_DIR}/liballegro_primitives.dylib)
endif(UNIX)
if(WIN32)
	set(ALLEGRO_BIN_DIR ${ALLEGRO_DIR}/bin)
	set(ALLEGRO_LIB_DIR ${ALLEGRO_DIR}/lib)

	set(ALLEGRO_LIB "${ALLEGRO_BIN_DIR}/allegro-5.0.10-md-debug.dll")
	set(ALLEGRO_IMPLIB "${ALLEGRO_LIB_DIR}/liballegro-5.0.10-md-debug.a")

	set(ALLEGRO_PRIM_LIB "${ALLEGRO_BIN_DIR}/allegro_primitives-5.0.10-md-debug.dll")
	set(ALLEGRO_PRIM_IMPLIB "${ALLEGRO_LIB_DIR}/liballegro_primitives-5.0.10-md-debug.a")
endif(WIN32)

link_directories(${ALLEGRO_LIB_DIR})

add_library(allegro SHARED IMPORTED)
set_target_properties(allegro PROPERTIES 
	IMPORTED_LOCATION 					${ALLEGRO_LIB}
	IMPORTED_IMPLIB 					${ALLEGRO_IMPLIB}
    INTERFACE_INCLUDE_DIRECTORIES 		"${ALLEGRO_DIR}/include"
)

add_library(allegro_primitives SHARED IMPORTED)
set_target_properties(allegro_primitives PROPERTIES
	IMPORTED_LOCATION				${ALLEGRO_PRIM_LIB}
	IMPORTED_IMPLIB					${ALLEGRO_PRIM_IMPLIB}
	INTERFACE_INCLUDE_DIRECTORIES 	"${ALLEGRO_DIR}/include"
)


file(GLOB SRCS src/*.cpp)
file(GLOB HEADERS headers/*.hpp)
add_executable(app ${SRCS} ${HEADERS})
add_dependencies(app allegro)
target_link_libraries(app allegro allegro_primitives)
target_include_directories(app PRIVATE headers)
