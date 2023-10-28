cmake_minimum_required(VERSION 3.15)

project(Exercicios)

set(CMAKE_CXX_STANDARD 20)  # Use the appropriate C++ standard

# Specify the source files and include directories
file(GLOB SOURCES "src/*.cpp")
include_directories(include)

# Define the executable target
add_executable(Exercicios ${SOURCES})
