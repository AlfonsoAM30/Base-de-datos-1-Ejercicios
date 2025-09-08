#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Arboles.h"
#include "Listas.h"
#include "tElemento.h"

int main() {
    FILE *file;
    char line[300];

    // Abrir el archivo en modo de lectura
    file = fopen("hashtags.txt", "r");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return EXIT_FAILURE;
    }

    // Leer el archivo línea por línea
    tElemento* elemento = (tElemento*)malloc(sizeof(tElemento));
    tNodoAr* arbol = NULL;
    crearArbolVacio(&arbol);
    int contador = 0;
    while (fgets(line, sizeof(line), file)) {
        line[strlen(line)-1] = '\0';
        tLista* lista = crearListaVacia();
        crearElemento(elemento, line, lista);
        Insertar(&arbol, elemento);
        contador++;
    }
    fclose(file);

    file = fopen("tweets.txt", "r");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return EXIT_FAILURE;
    }
    while (fgets(line, sizeof(line), file)) {
        int inicio = 0;
        int contador = 1;
        int empieza = 0;
        for (int i = 0; i < strlen(line); i++) {
            if (line[i] == '#') {
                inicio = i;
                empieza = 1;
                contador = 1;
            } else if (empieza && (line[i] == ' ' || line[i] == '\n' || line[i] == '.' || line[i] == ',' ||
                                   line[i] == '?' || line[i] == '!' || line[i] == ':' || line[i] == ';' || line[i] == '"')) {
                char* hashtag = (char*) malloc(contador + 1);
                strncpy(hashtag, line + inicio, contador);
                hashtag[contador] = '\0';
                buscar(&arbol, hashtag, line);
                //printf("(%s)\n", hashtag);
                free(hashtag);
                empieza = 0;
                contador = 0;
            } else if (empieza == 1) {
                contador++;
            }
        }
        //buscar(arbol, tweet);

    }

    printf("\n");
    //Inorder(arbol));
    printf("%i", contador);
    ImprimirTweets(&arbol, "#videogames");
    // Cerrar el archivo
    fclose(file);
    return EXIT_SUCCESS;
}
