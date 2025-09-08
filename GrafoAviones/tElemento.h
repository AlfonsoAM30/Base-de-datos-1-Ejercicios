//
// Created by setea on 12/12/2023.
//

#ifndef GRAFOAVIONES_TELEMENTO_H
#define GRAFOAVIONES_TELEMENTO_H

typedef struct elemeto{
    char company[20];
    float time;
    float price;
}tElemento;

void crearElemento(tElemento* destino, char company[20], float time, float price);

#endif //GRAFOAVIONES_TELEMENTO_H
