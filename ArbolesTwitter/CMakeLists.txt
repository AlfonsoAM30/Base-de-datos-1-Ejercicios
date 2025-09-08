cmake_minimum_required(VERSION 3.26)
project(ArbolesTwitter C)

set(CMAKE_C_STANDARD 11)

add_executable(ArbolesTwitter main.c
        Arboles.c
        Arboles.h
        Listas.c
        Listas.h
        tElemento.c
        tElemento.h)
