cmake_minimum_required(VERSION 3.26)
project(GrafoAviones C)

set(CMAKE_C_STANDARD 11)

add_executable(GrafoAviones main.c
        tGrafos.c
        tGrafos.h
        tListas.c
        tListas.h
        tElemento.c
        tElemento.h
        tListaPonderada.c
        tListaPonderada.h)
