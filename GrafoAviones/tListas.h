//
// Created by setea on 12/12/2023.
//

#ifndef GRAFOAVIONES_TLISTAS_H
#define GRAFOAVIONES_TLISTAS_H
#include "tElemento.h"
#include "tListaPonderada.h"

typedef struct nodoLista{
    char information[20];
    tListaPonderada* ponderaciones;
    struct nodoLista* next;
}tNodoLista;

typedef struct Lista{
    tNodoLista* cabeza;
    int longitud;
}tLista;

tLista* crearListaVacia();
void insertarLista(tLista* lista, char elem[20]);
int longitudLista(tLista* lista);
int estaVacio(tLista* lista);
int comprobarExisteDes(tLista* lista, char elem[20]);
void imprimirListaDestinos(tLista* lista);
void imprimirListaPon2(tLista* lista, char Destino[20]);
void imprimirPonderacionesyDestinos(tLista* lista);

#endif //GRAFOAVIONES_TLISTAS_H
