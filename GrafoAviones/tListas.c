//
// Created by setea on 12/12/2023.
//

#include "tListas.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

tLista* crearListaVacia(){
    tLista* lista = (tLista*) malloc(sizeof (tLista));
    lista->cabeza = NULL;
    lista->longitud = 0;
    return lista;
}

tNodoLista* crearNodoLista(char destino[20]){
    tNodoLista* newNode = (tNodoLista*) malloc(sizeof (tNodoLista));
    strcpy(newNode->information, destino);
    newNode->ponderaciones =  crearListaVaciaPonderada();
    newNode->next = NULL;
    return newNode;
}

void destrirNodoLista(tNodoLista* nodo){
    nodo->next = NULL;
    free(nodo);
}

int comprobarExisteDes(tLista* lista, char elem[20]){
    if(lista->cabeza){
        tNodoLista* puntero = lista->cabeza;
        while(puntero){
            if (strcmp(puntero->information, elem) == 0){
                return 1;
            }
            puntero = puntero->next;
        }
        return 0;
    }
}

void insertarLista(tLista* lista, char elem[20]){
    tNodoLista* newNode = crearNodoLista(elem);
    newNode->next = lista->cabeza;
    lista->cabeza = newNode;
    lista->longitud++;
}

int longitudLista(tLista* lista){
    return lista->longitud;
}

int estaVacio(tLista* lista){
    return lista->cabeza == NULL;
}

void imprimirElemetoLista(char informacion[20]){
    printf("%s, ",informacion);
}

void imprimirListaDestinos(tLista* lista){
    if(lista->cabeza){
        printf("(");
        tNodoLista* puntero = lista->cabeza;
        while(puntero){
            imprimirElemetoLista(puntero->information);
            puntero = puntero->next;
        }
        printf(")");
    }
}

void imprimirListaPon2(tLista* lista, char Destino[20]) {
    if (lista->cabeza) {
        int sol = 0;
        tNodoLista *puntero = lista->cabeza;
        while (puntero && sol == 0) {
            if (strcmp(puntero->information, Destino) == 0) {
                sol = 1;
            }
            puntero = puntero->next;
        }
        imprimirListaPonderada(puntero->ponderaciones);
    }
}

void imprimirPonderacionesyDestinos(tLista* lista){
    if (lista->cabeza){
        tNodoLista* puntero = lista->cabeza;
        while(puntero){
            printf("%s", puntero->information);
            imprimirListaPonderada(puntero->ponderaciones);
            puntero = puntero->next;
        }
    }
}
