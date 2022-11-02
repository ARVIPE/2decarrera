#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <pthread.h> //Incluir esta libreria para hilos
#include <stdbool.h>// Booleanos

int global = 0;

void * funcionHilo(){
    for(int i = 0; i < 10000; i++){
        global++;
    }
    pthread_exit((void*)NULL);
}

int main(){
    pthread_t idHilo1, idHilo2;
    pthread_create(&idHilo1, NULL, (void*)funcionHilo, NULL);
    pthread_create(&idHilo2, NULL, (void*)funcionHilo, NULL);
    pthread_join(idHilo1, (void**)NULL);
    pthread_join(idHilo2, (void**)NULL);
    printf("El valor de la siguiente global es %d\n", global);
    exit(EXIT_SUCCESS);
}