//
// Created by setea on 12/12/2023.
//

#include "tListaPonderada.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

tListaPonderada* crearListaVaciaPonderada(){
    tListaPonderada * lista = (tListaPonderada *) malloc(sizeof (tListaPonderada));
    lista->cabeza = NULL;
    lista->longitud = 0;
    return lista;
}

tNodoPon* crearNodoPon(tElemento* elemento){
    tNodoPon* newNodePon = (tNodoPon*) malloc(sizeof (tNodoPon));
    strcpy(newNodePon->elemento->company, elemento->company);
    newNodePon->elemento->time = elemento->time;
    newNodePon->elemento->price = elemento->price;
    newNodePon->sig = NULL;
    return newNodePon;
}

void destruirNodo(tNodoPon* nodo){
    nodo->sig = NULL;
    free(nodo);
}

void insertarListaPonderada(tListaPonderada* lista, tElemento* element){
    tNodoPon* nodo = crearNodoPon(element);
    nodo->sig = lista->cabeza;
    lista->cabeza = nodo;
    lista->longitud++;
}

int longitudListaPonderada(tListaPonderada * lista){
    return lista->longitud;
}

int estaVacioPonderada(tListaPonderada * lista){
    return lista->cabeza == NULL;
}

void imprimirElementoListaPon(tElemento* elemento){
    printf("Company: %s", elemento->company);
    printf("Price: %f.2", elemento->price);
    printf("Time: %f.2", elemento->time);
}

void imprimirListaPonderada(tListaPonderada * lista){
    if(lista->cabeza){
        tNodoPon* puntero = lista->cabeza;
        while(puntero){
            imprimirElementoListaPon(puntero->elemento);
            puntero = puntero->sig;
        }
    }
}