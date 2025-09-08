//
// Created by setea on 30/11/2023.
//

#include "tElemento.h"
#include "string.h"

void crearElemento(tElemento* destino, char hashtag[50], tLista* listaTweets){
    strcpy(destino->hashtag, hashtag);
    destino->listaTweets = listaTweets;
}
