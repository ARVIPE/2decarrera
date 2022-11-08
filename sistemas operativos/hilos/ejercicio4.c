// Ejercicio que al poner ./a.out 5 7 12 me haga el factorial de cada uno de los numeros. Cada uno son hilos
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <pthread.h> //Incluir esta libreria para hilos

void *factorial(char * numero)
{
    int tam = atoi(numero);
    int factorial = 1;

    for (int i = 0; i < tam; i++)
    {
        factorial += factorial * i;
    }

    printf("El factorial de : %d es %d\n", tam, factorial);

    pthread_exit((void *)NULL);
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Error no se ha introducido número");
        exit(EXIT_FAILURE);
    }

    // CREO LA VARIABLE DONDE GUARDO ID DEL HILO

    pthread_t id_hilo[argc - 1];

    for (int i = 0; i < (argc - 1); i++)
    {
        //int N = atoi(argv[i + 1]);
        pthread_create(&id_hilo[i], NULL, (void *)factorial, argv[i+1]);
    }

    for (int i = 0; i < (argc - 1); i++)
    {
        pthread_join(id_hilo[i], (void **)NULL);
    }

    // Matamos el hilo
    exit(EXIT_SUCCESS);
}