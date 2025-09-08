//
// Created by setea on 30/11/2023.
//

#include "Arboles.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"


void crearArbolVacio(tNodoAr** arbol){
    *arbol = NULL;
}

tNodoAr* crearNodoAr(tElemento* valor){
    tNodoAr* nuevoNodo = (tNodoAr*) malloc(sizeof(tNodoAr));
    if (nuevoNodo == NULL) {
        // Manejo de error si la asignación de memoria falla
        return NULL;
    }
    nuevoNodo->info = (tElemento*) malloc(sizeof(tElemento));
    if (nuevoNodo->info == NULL) {
        // Manejo de error si la asignación de memoria falla
        free(nuevoNodo);
        return NULL;
    }
    strcpy(nuevoNodo->info->hashtag, valor->hashtag);
    nuevoNodo->info->listaTweets = valor->listaTweets;
    nuevoNodo->izq = nuevoNodo->der = NULL;
    return nuevoNodo;
}

void destruirNodo(tNodoAr* nodo){
    nodo->izq = nodo->der = NULL;
    free(nodo);
}

void Insertar(tNodoAr** arbol, tElemento* elem){
    if ((*arbol) == NULL){
        *arbol = crearNodoAr(elem);
    } else {
        char raizValor[50];
        strcpy(raizValor, (*arbol)->info->hashtag);
        if(strcmp(elem->hashtag, raizValor) == -1){
            Insertar(&(*arbol)->izq, elem);
        } else {
            Insertar(&(*arbol)->der, elem);
        }
    }
}

void Inorder(tNodoAr* arbol){
    if(arbol == NULL){
    } else {
        Inorder(arbol->izq);
        printf("(%s)\n ", arbol->info->hashtag);
        Inorder(arbol->der);
    }
}


void buscar(tNodoAr** arbol, char* hashtag, char* tweet) {
    if ((*arbol) == NULL) {
        printf("%s\n", hashtag);
    } else {
        int cmp = strcmp((*arbol)->info->hashtag, hashtag);
        if (cmp == 0) {
            insertarLista((*arbol)->info->listaTweets, tweet);
        } else if (cmp < 0) {
            buscar(&(*arbol)->der, hashtag, tweet);
        } else {
            buscar(&(*arbol)->izq, hashtag, tweet);
        }
    }
}

void ImprimirTweets(tNodoAr** arbol, char* hastag){
    if(arbol == NULL){
        printf("No existe\n");
    } else {
        if(strcmp((*arbol)->info->hashtag, hastag) == 0){
            printf("\n(%s)\n",hastag);
            imprimirLista((*arbol)->info->listaTweets);
        } else if (strcmp((*arbol)->info->hashtag, hastag) == -1){
            ImprimirTweets(&(*arbol)->der, hastag);
        } else {
            ImprimirTweets(&(*arbol)->izq, hastag);
        }

    }
}