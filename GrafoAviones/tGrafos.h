//
// Created by setea on 12/12/2023.
//

#ifndef GRAFOAVIONES_TGRAFOS_H
#define GRAFOAVIONES_TGRAFOS_H
#include "tListas.h"

typedef struct nodoGrafo{
    char origen[20];
    tLista* destinos;
    struct nodoGrafo* siguiente;
}tNodoGrafo;

typedef struct Grafo{
    tNodoGrafo* cabeza;
    int longitud;
}tGrafo;

tGrafo* crearGrafoVacia();
void insertarGrafo(tGrafo* grafo, char elem[20]);
int comprobarExisteOr(tGrafo* grafo, char elem[20]);
void insertarDestinoConOrigen(tGrafo* grafo, char origen[20], char destino[20]);
void insertarListaPonderadaPorVez(tGrafo* grafo, char origen[20], char destino[20], char company[20], float price, float time);
int longitudGrafo(tGrafo* grafo);
int estaVacioGrafo(tGrafo* grafo);
void imprimirNodosGrafo(tGrafo* grafo);
void imprimirDestinos(tGrafo* grafo, char Origen[20]);
void imprimirListaDeonderaciones(tGrafo* grafo, char Origen[20], char Destino[20]);
void IMPRIMIRTODO(tGrafo* grafo);

#endif //GRAFOAVIONES_TGRAFOS_H
