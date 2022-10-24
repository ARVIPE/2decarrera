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

}