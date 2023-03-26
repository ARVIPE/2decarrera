#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <pthread.h> //Incluir esta libreria para hilos
#include <stdbool.h> // Booleanos
#include <time.h>
#include <stdlib.h>

pthread_mutex_t semaforo;
int variable = -1;

void *funcionSuma(char *numero)
{
    int tam = atoi(numero);
    for (int i = 0; i < tam; i++)
    {
        int num = rand() % 10;
        if (pthread_mutex_lock(&semaforo) != 0)
        {
            printf("error de lock\n");
            exit(EXIT_FAILURE);
        }
        variable += num;
        if (pthread_mutex_unlock(&semaforo) != 0)
        {
            printf("error de unlock\n");
            exit(EXIT_FAILURE);
        }
    }
    pthread_exit((void*)NULL);
}

void *funcionResta(char *numero)
{
    int tam = atoi(numero);
    for (int i = 0; i < tam; i++)
    {
        int num = rand() % 10;
        if (pthread_mutex_lock(&semaforo) != 0)
        {
            printf("error de lock\n");
            exit(EXIT_FAILURE);
        }
        variable -= num;
        if (pthread_mutex_unlock(&semaforo) != 0)
        {
            printf("error de unlock\n");
            exit(EXIT_FAILURE);
        }
    }
    pthread_exit((void*)NULL);
}

int main(int argc, char **argv)
{
    if(argc != 2){
        printf("ERROR: no se han introducido suficientes argumentos");
        exit(EXIT_FAILURE);
    }

    pthread_t escritor, lector;
    srand(time(NULL));
    if (pthread_mutex_init(&semaforo, NULL) != 0)
    {
        printf("error de inicio de semaforo\n");
        exit(EXIT_FAILURE);
    }

    if(pthread_create(&escritor, NULL, (void *)funcionSuma, argv[1])!=0){
        perror("No se ha creado el hilo");
        exit(EXIT_FAILURE);
    }
    pthread_create(&lector, NULL, (void *)funcionResta, argv[1]);
    pthread_join(escritor, (void **)NULL);
    pthread_join(lector, (void **)NULL);


    if (pthread_mutex_destroy(&semaforo) != 0)
    {
        printf("error al destruir el semaforo\n");
        exit(EXIT_FAILURE);
    }
    printf("El valor de la variable global es %d\n",variable);
    exit(EXIT_SUCCESS);
}