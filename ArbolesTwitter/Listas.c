//
// Created by setea on 30/11/2023.
//

#include "Listas.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"


tNodo* crearNodo(char elem[280]){
    tNodo* nuevoNodo = (tNodo*) malloc(sizeof (tNodo));
    strcpy(nuevoNodo->tweet, elem);
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

void destruir(tNodo* nodo){
    nodo->siguiente = NULL;
    free(nodo);
}

tLista* crearListaVacia(){
    tLista* lista = (tLista*)malloc(sizeof (tLista));
    lista->cabeza = NULL;
    lista->longitud = 0;
    return lista;
}

void insertarLista(tLista* lista, char elem[280]){
    tNodo* nodo = crearNodo(elem);
    nodo->siguiente = lista->cabeza;
    lista->cabeza
    = nodo;
    lista->longitud++;
}

int longitudLista(tLista* lista){
    return lista->longitud;
}

int estaVacio(tLista* lista) {
    return lista->cabeza == NULL;
}

void imprimirTweet(char elem[280]){
    printf("%s\n", elem);
}

void imprimirLista(tLista* lista){
    if (lista-> cabeza){
        tNodo* puntero = lista->cabeza;
        while(puntero){
            imprimirTweet(puntero->tweet);
            puntero = puntero->siguiente;
        }
    }
}