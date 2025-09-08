//
// Created by setea on 30/11/2023.
//

#ifndef ARBOLESTWITTER_TELEMENTO_H
#define ARBOLESTWITTER_TELEMENTO_H
#include "Listas.h"

typedef struct elemento{
    char hashtag[50];
    tLista* listaTweets;
}tElemento;

void crearElemento(tElemento* destino, char hashtag[50], tLista* listaTweets);

#endif //ARBOLESTWITTER_TELEMENTO_H
