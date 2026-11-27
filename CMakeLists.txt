cmake_minimum_required(VERSION 3.15)
project(BusquedaSumaParalelizada LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(proyecto
    src/main.cpp
    src/Calculadora.cpp
    src/CalculadoraSecuencial.cpp
    src/CalculadoraParalela.cpp
    src/Parciales.cpp
)

target_include_directories(proyecto PRIVATE include)
