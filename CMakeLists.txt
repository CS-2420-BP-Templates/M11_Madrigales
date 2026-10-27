cmake_minimum_required(VERSION 3.16)

project(LabOrdenamientoMadrigal LANGUAGES CXX)

# Estándar de C++ (C++17 funciona en todas las versiones recientes de CLion)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(lab_ordenamiento main.cpp)

# Advertencias útiles para estudiantes + soporte de UTF-8 (tildes y emojis)
if(MSVC)
    target_compile_options(lab_ordenamiento PRIVATE /W4 /utf-8)
else()
    target_compile_options(lab_ordenamiento PRIVATE -Wall -Wextra -Wpedantic)
endif()
