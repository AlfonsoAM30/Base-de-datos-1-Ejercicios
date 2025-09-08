//
// Created by setea on 12/12/2023.
//

#include "tElemento.h"
#include "string.h"

void crearElemento(tElemento* destino, char company[20], float time, float price){
    strcpy(destino->company, company);
    destino->time = time;
    destino->price = price;
}