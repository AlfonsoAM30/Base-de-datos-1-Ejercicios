//
// Created by setea on 12/12/2023.
//

#ifndef GRAFOAVIONES_TLISTAPONDERADA_H
#define GRAFOAVIONES_TLISTAPONDERADA_H
#include "tElemento.h"

typedef struct nodoPon{
    tElemento* elemento;
    struct nodoPon* sig;
}tNodoPon;

typedef struct listaPon{
    tNodoPon* cabeza;
    int longitud;
}tListaPonderada;

tListaPonderada* crearListaVaciaPonderada();
void insertarListaPonderada(tListaPonderada * lista, tElemento* element);
int longitudListaPonderada(tListaPonderada * lista);
int estaVacioPonderada(tListaPonderada * lista);
void imprimirListaPonderada(tListaPonderada * lista);

#endif //GRAFOAVIONES_TLISTAPONDERADA_H
