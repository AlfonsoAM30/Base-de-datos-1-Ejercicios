//
// Created by setea on 30/11/2023.
//

#ifndef ARBOLESTWITTER_ARBOLES_H
#define ARBOLESTWITTER_ARBOLES_H
#include "Listas.h"
#include "tElemento.h"

typedef struct nodoArol{
    tElemento* info;
    struct nodoArol* izq;
    struct nodoArol* der;
}tNodoAr;

typedef tNodoAr* tArbol;

void crearArbolVacio(tNodoAr** arbol);
tNodoAr* crearNodoAr(tElemento* valor);
void destruirNodo(tNodoAr* nodo);
void Insertar(tNodoAr** arbol, tElemento* elem);
void eliminar(tArbol* a, tElemento* e);
void Inorder(tNodoAr* arbol);
void buscar(tNodoAr** arbol, char* hastag, char* tweet);
void ImprimirTweets(tNodoAr** arbol, char* hastag);
#endif //ARBOLESTWITTER_ARBOLES_H
