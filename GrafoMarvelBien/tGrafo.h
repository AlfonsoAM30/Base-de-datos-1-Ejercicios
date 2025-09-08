//
// Created by setea on 05/12/2023.
//

#ifndef GRAFOMARVELBIEN_TGRAFO_H
#define GRAFOMARVELBIEN_TGRAFO_H
#include "tElemento.h"

typedef struct nodoLista{
    tElemento super;
    int escenas;
    struct nodoLista* siguiente;
}tNodoLista;

typedef tNodoLista* tLista;

typedef struct nodo{
    tElemento superHeroe;
    tLista* superConectados;
    struct nodo* siguiente;
}tNodoGrafo;

typedef tNodoGrafo* tGrafo;

void insertarSuperHerore(tGrafo* grafo, char* nombre, int v, int f);

#endif //GRAFOMARVELBIEN_TGRAFO_H
