//Crear un vector aleatorio de tam 10 rellenado con los numeros que nos de la gana. Luego creamos 10 hilos, los de creación par deberan de comprobar si el numero
//situado en su posición es primo o no. Mientras que los hilos de creación impar deberan de comprobar si es perfecto o no.
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <pthread.h> //Incluir esta libreria para hilos
#include<stdbool.h>// Booleanos

bool * perfecto(char * numero){
    int tam = atoi(numero);
    int perfecto = 0;

    for(int i = 0; i < tam; i++){
        int num = tam%i;
        if(num == 0){
            perfecto += num;
        }
    }

    if(perfecto == tam){
        return true;
    }else{
        return false;
    }

}

int main()
{
 
    //CREO LA VARIABLE DONDE GUARDO ID DEL HILO
    pthread_t id_hilo1;

    //CREAR EL HILO
    pthread_create(&id_hilo1, NULL, (void*)perfecto, numero);


    //ESPERAR AL HILO
    pthread_join(id_hilo1, (void**)NULL);
  

   //Matamos el hilo
   exit(EXIT_SUCCESS);
}