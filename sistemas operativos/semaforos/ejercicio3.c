// Ejercicio 2 practica 3

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

int par, impar = 0;
pthread_mutex_t semaforo, semaforo1;

void *generarNum(int *posicion)
{
    if (pthread_mutex_lock(&semaforo) != 0)
    {
        printf("error\n");
        exit(EXIT_FAILURE);
    }
    int pos = *posicion;
    printf("La pos es : %i\n", *posicion);
    if (pthread_mutex_unlock(&semaforo) != 0)
    {
        printf("error\n");
        exit(EXIT_FAILURE);
    }

    int suma = 0;

    for (int i = 0; i < 5; i++)
    {
        if (pthread_mutex_lock(&semaforo1) != 0)
        {
            printf("error\n");
            exit(EXIT_FAILURE);
        }

        suma += rand() % 10;

        if (pos % 2 == 0)
        {

            par += suma;
        }
        else
        {

            impar += suma;
        }
        if (pthread_mutex_unlock(&semaforo1) != 0)
        {
            printf("error\n");
            exit(EXIT_FAILURE);
        }
    }

    int *retorno = (int *)malloc(sizeof(int));
    (*retorno) = suma;
    pthread_exit((void *)retorno);
}

int main(int argc, char **argv)
{
    int N = atoi(argv[1]);
    pthread_t idHilos[N];
    srand(time(NULL));
    if (pthread_mutex_init(&semaforo, NULL) != 0)
    {
        printf("error\n");
        exit(EXIT_FAILURE);
    }

    if (pthread_mutex_init(&semaforo1, NULL) != 0)
    {
        printf("error\n");
        exit(EXIT_FAILURE);
    }

    if (argc != 2)
    {
        printf("ERROR: no se han introducido suficientes argumentos");
        exit(EXIT_FAILURE);
    }

    int variable[N];
    for (int i = 0; i < N; i++)
    {

        variable[i] = i;

        if (pthread_create(&idHilos[i], NULL, (void *)generarNum, (void *)&variable[i]) != 0)
        {
            printf("error al crear un hilo\n");
            exit(EXIT_FAILURE);
        }
    }

    int *valorRecogido;
    int sumaPar, sumaImpar = 0;
    for (int i = 0; i < N; i++)
    {
        if (pthread_join(idHilos[i], (void **)&valorRecogido) != 0){
            printf("error en la espera\n");
            exit(EXIT_FAILURE);
        }

        printf("La hebra de orden de creación %d devolvió el valor de suma total: %d\n", i, (*valorRecogido));

        if (i % 2 == 0)
        {
            sumaPar += *valorRecogido;
        }
    }

    printf("El valor de la variable par es de : %i\n", par);
    printf("El valor de la suma par es de: %i\n", sumaPar);

    if (pthread_mutex_destroy(&semaforo) != 0)
    {
        printf("error\n");
        exit(EXIT_FAILURE);
    }
    if (pthread_mutex_destroy(&semaforo1) != 0)
    {
        printf("error\n");
        exit(EXIT_FAILURE);
    }
}
