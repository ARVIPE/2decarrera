#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <pthread.h> //Incluir esta libreria para hilos

void * saluda(char * cadena){
    for(int i = 0; i < strlen(cadena); i++){
        printf("%c\n", cadena[i]);
        sleep(1);
    }
    pthread_exit((void*)NULL);
}

int main()
{
    char cadena1[]="Hola", cadena2[]="Mundo";
    //CREO LA VARIABLE DONDE GUARDO ID DEL HILO
    pthread_t id_hilo1, id_hilo2;

    //CREAR EL HILO
    pthread_create(&id_hilo1, NULL, (void*)saluda, cadena1);
    pthread_create(&id_hilo2, NULL, (void*)saluda, cadena2);

    //ESPERAR AL HILO
    pthread_join(id_hilo1, (void**)NULL);
    pthread_join(id_hilo2, (void**)NULL);

   //Matamos el hilo
   exit(EXIT_SUCCESS);
}