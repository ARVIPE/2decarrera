//Ejercicio que le pasamos el numero de hilos si por ejemplo le pasamos 7 y me haga 7 veces un sumador de 1 y cuando termine el sumador que haga un restador 7 veces. Queremos un hilo
//por cada sumador y otro por cada restador. Es decir en este ejemplo habriamos creado 14 hilos.
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

void * funcionSuma(){
    
}


int main(int argc, char **argv){

    if(argc !=2){
        printf("ERROR: no se han introducido suficientes argumentos");
        exit(EXIT_FAILURE);
    }
    int N = atoi(argv[1]);
    pthread_t id_hiloSum[N], id_hiloRes[N];

    for(int i = 0; i < N; i++){
        if(pthread_create(&id_hiloSum[i], NULL, (void*)funcionSuma, NULL)!=0){
            
        }
    }



}