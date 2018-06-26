# cmake --version
cmake_minimum_required(VERSION 2.6)

set(PROJECT_NAME "simplecoin")

# project name
project(${PROJECT_NAME})

# source file list
set(SOURCES
	main.c
)

add_executable(${PROJECT_NAME} ${SOURCES})

# shared library list
set(LIBS
	"-lssl"
)

target_link_libraries(${PROJECT_NAME} ${LIBS})
