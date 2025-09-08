//
// Created by setea on 30/11/2023.
//

#ifndef ARBOLESTWITTER_LISTAS_H
#define ARBOLESTWITTER_LISTAS_H

typedef struct nodo{
    char tweet[280];
    struct nodo* siguiente;
}tNodo;

typedef struct lista{
    tNodo* cabeza;
    int longitud;
}tLista;

//tNodo* crearNodo(char elem[280]);
//void destruirNodo(tNodo* nodo);

tLista* crearListaVacia();
void insertarLista(tLista* lista, char elem[280]);
int longitudLista(tLista* lista);
int estaVacio(tLista* lista);
void imprimirLista(tLista* lista);


#endif //ARBOLESTWITTER_LISTAS_H
