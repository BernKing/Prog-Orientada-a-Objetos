cmake_minimum_required(VERSION 3.15)

project(Caderno_Exericicios)

set(CMAKE_CXX_STANDARD 20)  # Use the appropriate C++ standard

# Specify the source files and include directories
file(GLOB SOURCES "src/*.cpp")
include_directories(include)

# Define the executable target
add_executable(Exercicios ${SOURCES})

# Add your source files
add_executable(main main.cpp operario.cpp administrativo.cpp funcionario.cpp pessoa.cpp data.cpp)

# Optionally, include directories for header files
include_directories(C:/Users/ASUS/Documents/GitHub/Prog.-Orientada-a-Objetos/Caderno_Exericios/include)