// Ejercicio 2 practica 3

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

int main(int argc, char **argv)
{

    if (argc != 2)
    {
        printf("ERROR: no se han introducido suficientes argumentos");
        exit(EXIT_FAILURE);
    }

    int N = atoi(argv[1]);

    int par, impar = 0;

    pthread_t hilos[N];

    for (int i = 0; i < 5; i++)
    {
        


    }
}
