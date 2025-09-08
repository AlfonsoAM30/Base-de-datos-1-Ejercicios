#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "tGrafos.h"
#include "tListas.h"
#include "tElemento.h"
#include "tListaPonderada.h"


int main() {
    FILE *file;
    char line[20];

    file = fopen("vuelos.txt", "r");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return EXIT_FAILURE;
    }

    tElemento* elemento = (tElemento*) malloc(sizeof (tElemento));
    tGrafo* grafo = crearGrafoVacia();
    char origenAux[20];
    char destinoAux[20];
    char companyAux[20];
    float priceAux;
    float timeAux;
    int contador = 0;
    while (fgets(line, sizeof(line), file)) {
        line[strlen(line)-1] = '\0';
        if (contador == 0){
            if (comprobarExisteOr(grafo, line) == 0){
                insertarGrafo(grafo, line);
            }
            strcpy(origenAux, line);
            contador++;
        } else if (contador == 1) {
            insertarDestinoConOrigen(grafo, origenAux, line);
            strcpy(destinoAux, line);
            contador++;
        } else if (contador == 2) {
            strcpy(companyAux, line);
            contador++;
        } else if (contador == 3) {
            fscanf(file, "%f", priceAux);
            contador++;
        } else if (contador == 4){
            fscanf(file, "%f\n", timeAux);
            insertarListaPonderadaPorVez(grafo, origenAux, destinoAux, companyAux, timeAux, priceAux);
            contador = 0;
        }
    }


}
