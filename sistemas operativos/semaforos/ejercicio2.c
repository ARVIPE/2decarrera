// Cree un programa al que se le introduzcan dos valores y haga con el primer valor una suma recursiva de numeros generados aleatoriamente y con el segundo lo  mismo pero
// restando recursivamente.

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

int global = 0;
pthread_mutex_t semaforo;

void *suma(int *num)
{
    printf("el num es de: %i\n", *num);
    for (int i = 0; i < (*num); i++)
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
void *resta(int *num)
{
    for (int i = 0; i < (*num); i++)
    {
        if (pthread_mutex_lock(&semaforo) != 0)
        {
            printf("error\n");
            exit(EXIT_FAILURE);
        }
        global--;
        if (pthread_mutex_unlock(&semaforo) != 0)
        {
            printf("error\n");
            exit(EXIT_FAILURE);
        }
    }
    pthread_exit((void *)NULL);
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("error en linea de argumentos\n");
        exit(EXIT_FAILURE);
    }
    if (pthread_mutex_init(&semaforo, NULL) != 0)
    {
        printf("error\n");
        exit(EXIT_FAILURE);
    }
    srand(time(NULL));
    int resultado = 0;
    pthread_t hilos_sum[atoi(argv[1])], hilos_rest[atoi(argv[2])];
    int valores_sum[atoi(argv[1])], valores_rest[atoi(argv[2])];

    for (int i = 0; i < atoi(argv[1]); i++)
    {
        valores_sum[i] = rand() % 1001;
        resultado += valores_sum[i];
        if (pthread_create(&hilos_sum[i], NULL, (void *)suma, &valores_sum[i]) != 0)
        {
            printf("error al crear un hilo\n");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < atoi(argv[2]); i++)
    {
        valores_rest[i] = rand() % 1001;
        resultado -= valores_rest[i];
        if (pthread_create(&hilos_rest[i], NULL, (void *)resta, &valores_rest[i]) != 0)
        {
            printf("error al crear un hilo\n");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < atoi(argv[1]); i++)
    {
        if (pthread_join(hilos_sum[i], (void **)NULL) != 0)
        {
            printf("error en la espera\n");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < atoi(argv[2]); i++)
    {
        if (pthread_join(hilos_rest[i], (void **)NULL) != 0)
        {
            printf("error en la espera\n");
            exit(EXIT_FAILURE);
        }
    }
    if (pthread_mutex_destroy(&semaforo) != 0)
    {
        printf("error\n");
        exit(EXIT_FAILURE);
    }

    if (global != resultado)
    {
        printf("resultado incorrecto\n");
    }
    else
    {
        printf("resultado correcto\n");
    }
    exit(EXIT_SUCCESS);
}