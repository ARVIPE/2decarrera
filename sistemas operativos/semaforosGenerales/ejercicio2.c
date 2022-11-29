#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

sem_t e;
sem_t s;
sem_t n;
int v[5];

void mostrarvector()
{
    for (int i = 0; i < 5; i++)
    {
        printf("%i ", v[i]);
    }
    printf("\n");
}

void inicializarVector()
{
    for (int i = 0; i < 5; i++)
    {
        v[i] = 0;
    }
}

void *productor()
{
    for (int i = 0; i < 10; i++)
    {
        int num = rand() % 5;
        sem_wait(&e);
        sem_wait(&s);
        printf("Hilo %lu produce 1 en la posicion %d\n", pthread_self(), num);
        v[num]++;
        sem_post(&s);
        sem_post(&n);
    }
}
void *consumidor()
{
    for (int i = 0; i < 10; i++)
    {
        int num = rand() % 5;
        sem_wait(&n);
        sem_wait(&s);
        printf("Hilo %lu consume 1 en la posicion %d\n", pthread_self(), num);
        v[num]--;
        sem_post(&s);
        sem_post(&e);
    }
}

int main()
{
    srand(time(NULL));
    sem_init(&e, 0, 5);
    sem_init(&s, 0, 1);
    sem_init(&n, 0, 0);
    pthread_t hilo;
    pthread_t hilo2;
    inicializarVector();
    printf("Antes de empezar: ");
    mostrarvector();
    if (pthread_create(&hilo, NULL, (void *)productor, NULL) != 0)
    {
        printf("error al crear un hilo\n");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&hilo2, NULL, (void *)consumidor, NULL) != 0)
    {
        printf("error al crear un hilo\n");
        exit(EXIT_FAILURE);
    }
    if (pthread_join(hilo, NULL) != 0)
    {
        printf("error\n");
        exit(EXIT_FAILURE);
    }
    if (pthread_join(hilo2, NULL) != 0)
    {
        printf("error\n");
        exit(EXIT_FAILURE);
    }
    sem_destroy(&e);
    sem_destroy(&s);
    sem_destroy(&n);
    printf("Al finalizar: ");
    mostrarvector();
}