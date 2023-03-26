#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
pthread_mutex_t semaforo;
int global = 0;

void *funcionHilo()
{
    for (int i = 0; i < 10000; i++)
    {
        if (pthread_mutex_lock(&semaforo) != 0)
        {
            printf("error\n");
            exit(EXIT_FAILURE);
        }
        global++;
        if (pthread_mutex_unlock(&semaforo) != 0)
        {
            printf("error\n");
            exit(EXIT_FAILURE);
        }
    }
    pthread_exit((void *)NULL);
}
int main()
{
    pthread_t idhilo1, idhilo2;
    if (pthread_mutex_init(&semaforo, NULL) != 0)
    {
        printf("error\n");
        exit(EXIT_FAILURE);
    }
    pthread_create(&idhilo1, NULL, (void *)funcionHilo, NULL);
    pthread_create(&idhilo2, NULL, (void *)funcionHilo, NULL);
    pthread_join(idhilo1, (void **)NULL);
    pthread_join(idhilo2, (void **)NULL);
    if (pthread_mutex_destroy(&semaforo) != 0)
    {
        printf("error\n");
        exit(EXIT_FAILURE);
    }
    printf("el valor de la variable global es %d\n", global);
    exit(EXIT_SUCCESS);
}