// Ejercicio 2 de practica 2
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <pthread.h> //Incluir esta libreria para hilos
#include <stdbool.h>// Booleanos

int contarLineas(char *nF)
{
    FILE *fich = fopen(nF, "r");
    if (fich == NULL)
    {
        printf("Error...");
        exit(EXIT_FAILURE);
    }
    int cont = 0;
    char cadena[200];
    while (fgets(cadena, 200, fich))
    {
        cont++;
    }
    fclose(fich);
    return cont;
}

int main(int argc, char **argv)
{
    // CREO LA VARIABLE DONDE GUARDO ID DEL HILO
    int N = atoi(argv[1]);
    pthread_t idHilos[N];
    if (argc < 2)
    {
        printf("ERROR: tienes que pasarle al menos un fichero\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < (argc - 1); i++)
    {
        // Control de errores al crear hilo
        if (pthread_create(&idHilos[N], NULL, (void *)contarLineas, argv[i+1])!=0)
        {
            printf("ERROR...");
            exit(EXIT_FAILURE);
        }
        printf("He recodigo un %i\n fichero", (contarLineas));
    }
}