cmake_minimum_required(VERSION 3.0)
project(Caderno_Exericios)

set(CMAKE_CXX_STANDARD 11)

# Add include directories
include_directories(include)

# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Create an executable
add_executable(exercicios ${SOURCES})
