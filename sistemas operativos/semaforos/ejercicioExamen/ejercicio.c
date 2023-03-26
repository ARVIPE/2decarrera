//Ejercicio que le pasamos el numero de hilos si por ejemplo le pasamos 7 y me haga 7 veces un sumador de 1 y cuando termine el sumador que haga un restador 7 veces. Queremos un hilo
//por cada sumador y otro por cada restador. Es decir en este ejemplo habriamos creado 14 hilos.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
int global = 0;
pthread_mutex_t semaforo;

void * sumador(){
    if(pthread_mutex_lock(&semaforo)!=0){
        printf("ERROR: al bloquear el semaforo\n");
        perror("ERROR: al bloquear el semaforo\n");
        exit(EXIT_FAILURE);
    }
    global++;
    if(pthread_mutex_unlock(&semaforo)!=0){
        printf("ERROR: al desbloquear el semaforo\n");
        perror("ERROR: al desbloquear el semaforo\n");
        exit(EXIT_FAILURE);
    }
    pthread_exit((void*)NULL);
}

void * restador(){
    if(pthread_mutex_lock(&semaforo)!=0){
        printf("ERROR: al bloquear el semaforo\n");
        perror("ERROR: al bloquear el semaforo\n");
        exit(EXIT_FAILURE);
    }
    global--;
    if(pthread_mutex_unlock(&semaforo)!=0){
        printf("ERROR: al desbloquear el semaforo\n");
        perror("ERROR: al desbloquear el semaforo\n");
        exit(EXIT_FAILURE);
    }
    pthread_exit((void*)NULL);
}



int main(int argc, char ** argv){
    
    if(argc != 2){
        printf("ERROR: no se han introducido suficientes argumentos\n");
        perror("ERROR: no se han introducido suficientes argumentos\n");
        exit(EXIT_FAILURE);
    }

    pthread_mutex_init(&semaforo, NULL);

    int N = atoi(argv[1]);

    pthread_t idhilo1[N];
    pthread_t idhilo2[N];

    for(int i = 0; i < N; i++){
        if(pthread_create(&idhilo1[i], NULL, (void*)sumador, NULL)){
            printf("ERROR: al crear el hilo");
            perror("ERROR: al crear el hilo");
            exit(EXIT_FAILURE);
        }
        if(pthread_create(&idhilo2[i], NULL, (void*)restador, NULL)){
            printf("ERROR: al crear el hilo");
            perror("ERROR: al crear el hilo");
            exit(EXIT_FAILURE);
        }
       
    }

    for(int i = 0; i < N; i++){
        if(pthread_join(idhilo1[i], (void**)NULL)!=0){
            printf("ERROR: en la espera del hilo\n");
            perror("ERROR: en la espera del hilo\n");
            exit(EXIT_FAILURE);
        }
        if(pthread_join(idhilo2[i], (void**)NULL)!=0){
            printf("ERROR: en la espera del hilo\n");
            perror("ERROR: en la espera del hilo\n");
            exit(EXIT_FAILURE);
        }
    }
    
    

    if(pthread_mutex_destroy(&semaforo)!=0){
        printf("ERROR: en la destrucción del semaforo\n");
        perror("ERROR: en la destruccion del semaforo\n");
        exit(EXIT_FAILURE);
    }

    printf("El valor de la variable global es de: %d\n",global);
    exit(EXIT_SUCCESS);
}
