//
// Created by setea on 12/12/2023.
//

#include "tGrafos.h"
#include "tListas.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


tGrafo* crearGrafoVacia(){
    tGrafo* grafo = (tGrafo*) malloc(sizeof (tGrafo));
    grafo->cabeza = NULL;
    grafo->longitud = 0;
    return grafo;
}

tNodoGrafo* crearNodoGrafo(char origen[20]){
    tNodoGrafo* newNode = (tNodoGrafo*) malloc(sizeof(tNodoGrafo));
    strcpy(newNode->origen, origen);
    newNode->destinos = crearListaVacia();
    newNode->siguiente = NULL;
    return newNode;
}

void destruirNodoGrafo(tNodoGrafo* nodo){
    nodo->siguiente = NULL;
    free(nodo);
}

int comprobarExisteOr(tGrafo* grafo, char elem[20]){
    if(grafo->cabeza){
        tNodoGrafo* puntero = grafo->cabeza;
        while(puntero){
            if (strcmp(puntero->origen, elem) == 0){
                return 1;
            }
            puntero = puntero->siguiente;
        }
        return 0;
    }
}

void insertarDestinoConOrigen(tGrafo* grafo, char origen[20], char destino[20]){
    if(grafo->cabeza){
        tNodoGrafo* puntero = grafo->cabeza;
        while(puntero){
            if (strcmp(puntero->origen, origen) == 0){
                if (comprobarExisteDes(grafo->cabeza->destinos, destino) == 0){
                    insertarLista(grafo->cabeza->destinos, destino);
                    return;
                }
            }
            puntero = puntero->siguiente;
        }
    }
}

void insertarListaPonderadaPorVez(tGrafo* grafo, char origen[20], char destino[20], char company[20], float time, float price){
    tElemento* elemento = (tElemento*) malloc(sizeof (tElemento));
    crearElemento(elemento, company, time, price);
    if(grafo->cabeza){
        tNodoGrafo* puntero = grafo->cabeza;
        while(puntero){
            if (strcmp(puntero->origen, origen) == 0){
                tNodoLista* puntero2 = grafo->cabeza->destinos->cabeza;
                while (puntero2){
                    if (strcmp(puntero2->information, destino) == 0) {
                        insertarListaPonderada(grafo->cabeza->destinos->cabeza->ponderaciones, elemento);
                    }
                    puntero2 = puntero2->next;
                }
            }
            puntero = puntero->siguiente;
        }
    }
}

void insertarGrafo(tGrafo* grafo, char elem[20]){
    tNodoGrafo* newNode = crearNodoGrafo(elem);
    newNode->siguiente = grafo->cabeza;
    grafo->cabeza = newNode;
    grafo->longitud++;
}

int longitudGrafo(tGrafo* grafo){
    return grafo->longitud;
}

int estaVacioGrafo(tGrafo* grafo){
    return grafo->cabeza == NULL;
}

void imprimirOrigen(char origen[20]){
    printf("%s, ", origen);
}

void imprimirNodosGrafo(tGrafo* grafo){
    if(grafo->cabeza){
        printf("(");
        tNodoGrafo* puntero = grafo->cabeza;
        while(puntero){
            imprimirOrigen(puntero->origen);
            puntero = puntero->siguiente;
        }
        printf(")");
    }
}

void imprimirDestinos(tGrafo* grafo, char Origen[20]){
    if(grafo->cabeza){
        int sol = 0;
        tNodoGrafo* puntero = grafo->cabeza;
        while(puntero && sol == 0){
            if(strcmp(puntero->origen, Origen) == 0){
                sol = 1;
            }
            puntero = puntero->siguiente;
        }
        imprimirListaDestinos(puntero->destinos);
    }
}

void imprimirListaDeonderaciones(tGrafo* grafo, char Origen[20], char Destino[20]){
    if(grafo->cabeza){
        int sol = 0;
        tNodoGrafo* puntero = grafo->cabeza;
        while(puntero && sol == 0){
            if(strcmp(puntero->origen, Origen) == 0){
                sol = 1;
            }
            puntero = puntero->siguiente;
        }
        imprimirListaPon2(puntero->destinos, Destino);
    }
}

void IMPRIMIRTODO(tGrafo* grafo){
    if(grafo->cabeza){
        tNodoGrafo* puntero = grafo->cabeza;
        while(puntero){
            printf("%s", puntero->origen);
            imprimirPonderacionesyDestinos(puntero->destinos);
            puntero = puntero->siguiente;
        }
    }
}