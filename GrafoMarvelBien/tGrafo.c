//
// Created by setea on 05/12/2023.
//

#include "tGrafo.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

void insertarSuperHerore(tGrafo* grafo, char* nombre, int v, int f){
    tElemento* NsuperHeroe = (tElemento*)malloc(sizeof(tElemento));
    tNodoGrafo* nuevo = (tNodoGrafo*) malloc(sizeof (tNodoGrafo));
    crearSuperHero(NsuperHeroe, nombre, v, f);
    asignarSuperHeroe(&(*nuevo).superHeroe, NsuperHeroe);
    crearListaVacia(&(*nuevo).superConectados);
    (*nuevo).siguiente = *grafo;
    (*grafo) = nuevo;
}

void crearUnaConexion(tGrafo* grafo, tElemento super1, tElemento super2, int escenas){
    tNodoGrafo* aux = *grafo;
    while(iguales(aux->superHeroe, super1) == 0){
        aux = aux->siguiente;
    }
    tNodoLista* nodo = (tNodoLista*) malloc(sizeof (tNodoLista));
    asignarSuperheroe(&(nodo)->super, super2);
    //nodo->escenas = escenas;
    asignarEscenas(&(nodo)->super, escenas);
    nodo->siguiente = *aux->superConectados;
    aux->superConectados = &nodo;
}

void crearConexion(tGrafo* grafo, tElemento super1, tElemento super2, int escenas){
    char nombre1 = obtenerNombre(&super1);
    char nombre2 = obtenerNombre(&super2);
    int numEscenas = numeroSecuencia(grafor, nombre1, nombre2);
    if (numEscenas == 0){
        crearUnaConexion(grafo, super1, super2, escenas);
        crearUnaConexion(grafo, super2, super1, escenas);
    }
}


