cmake_minimum_required(VERSION 3.5)
project(practicaFinal)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Baralla.cpp Baralla.h Joc.cpp Joc.h Tauler.cpp Tauler.h Carta.cpp Carta.h pilaCartes.cpp pilaCartes.h)
add_executable(practicaFinal ${SOURCE_FILES})