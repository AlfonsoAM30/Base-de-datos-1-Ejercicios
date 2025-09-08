cmake_minimum_required(VERSION 3.26)
project(GrafoMarvelBien C)

set(CMAKE_C_STANDARD 11)

add_executable(GrafoMarvelBien main.c
        tElemento.c
        tElemento.h
        tGrafo.c
        tGrafo.h)
