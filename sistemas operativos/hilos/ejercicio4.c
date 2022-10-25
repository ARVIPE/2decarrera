//Ejercicio que al poner ./a.out 5 7 12 me haga el factorial de cada uno de los numeros. Cada uno son hilos
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <pthread.h> //Incluir esta libreria para hilos

void * factorial(char * numero){
    int tam = atoi(numero);
    if (tam < 2)
    {
        printf("Error no se ha introducido número");
        exit(EXIT_FAILURE);
    }
    int factorial = 1;
    
    for (int i = 0; i < tam; i++)
    {
        factorial += factorial * i;
    }

    pthread_exit((void*)NULL);
}

int main(int argc, char ** argv)
{
    int tam = atoi(argv[1]);
    //CREO LA VARIABLE DONDE GUARDO ID DEL HILO
    pthread_t id_hilo;

    pthread_create(&id_hilo, NULL, (void*)factorial(tam), NULL);

    pthread_join(id_hilo, (void**)NULL);
  

   //Matamos el hilo
   exit(EXIT_SUCCESS);
}