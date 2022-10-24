#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <pthread.h> //Incluir esta libreria para hilos

void * saluda(){
    printf("Hola mundo \n");
    pthread_exit((void*)NULL);
}

int main()
{
    //CREO LA VARIABLE DONDE GUARDO ID DEL HILO
    pthread_t id_hilo;
    //CREAR EL HILO
    /* 
        1 argumento) Variable por referencia donde guardo el ID de hilo
        2 argumento) Siempre NULL
        3 argumento) (void*)nombreFunción
        4 argumento) NULL si la función del hilo no recibe argumento o (void*)&variable siendo variable la pasada como argumento a la función
    */
    pthread_create(&id_hilo, NULL, (void*)saluda, NULL);
    //ESPERAR AL HILO
    pthread_join(id_hilo, (void**)NULL);
    /*
        Variable que contiene el identificador del hilo a esperar
        void** seguido de NULL si la función no devuelve nada o &* que retornará el valor de la función 
    */
   //Matamos el hilo
   exit(EXIT_SUCCESS);
}