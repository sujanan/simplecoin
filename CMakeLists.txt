# cmake --version
cmake_minimum_required(VERSION 2.6)

# project name variable
set(PROJECT_NAME "simplecoin")

# project name
project(${PROJECT_NAME})

# source file list
set(SOURCES_LIB
	simplecoin.h
	simplecoin.c
)

set(SOURCES
	${SOURCES_LIB}
	main.c
)

# add main executables
add_executable(${PROJECT_NAME} ${SOURCES})

# shared library list
set(LIBS
	"-lssl"
	"-lcrypto"
)

# add shared library list
target_link_libraries(${PROJECT_NAME} ${LIBS})

# create a static library
add_library(libsimplecoin STATIC ${SOURCES})

# testing
enable_testing()

# sub directory for testing
add_subdirectory(test)
