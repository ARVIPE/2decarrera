#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <errno.h>
#include <time.h>

pthread_mutex_t s;
int variable = -1;

void * suma(int * num){


    if(pthread_mutex_lock(&s)!=0){
        perror("ERROR: al bloquear el semaforo\n");
        printf("ERROR: al bloquear el semaforo\n");
        exit(EXIT_FAILURE);
    }
    printf("%d\n", *num);
    variable+=*num;
    if(pthread_mutex_unlock(&s)!=0){
        perror("ERROR: al bloquear el semaforo\n");
        printf("ERROR: al bloquear el semaforo\n");
        exit(EXIT_FAILURE);
    }

    pthread_exit((void*)NULL);
}

void * resta(int * num){


    if(pthread_mutex_lock(&s)!=0){
        perror("ERROR: al bloquear el semaforo\n");
        printf("ERROR: al bloquear el semaforo\n");
        exit(EXIT_FAILURE);
    }
    printf("%d\n", *num);
    variable= variable - *num;
    if(pthread_mutex_unlock(&s)!=0){
        perror("ERROR: al bloquear el semaforo\n");
        printf("ERROR: al bloquear el semaforo\n");
        exit(EXIT_FAILURE);
    }

    pthread_exit((void*)NULL);
}

int main(int argc, char ** argv){

    if(pthread_mutex_init(&s, NULL)!=0){
        perror("ERROR: al crear el semaforo\n");
        printf("ERROR: al crear el semaforo\n");
        exit(EXIT_FAILURE);
    }

    if(argc != 2){
        perror("ERROR: no se han introducio suficientes argumentos\n");
        printf("ERROR: no se han introducido suficientes argumentos\n");
        exit(EXIT_FAILURE);
    }
    
    srand(time(NULL));
    pthread_t escritor, lector;
    int N1 = atoi(argv[1]);



    for(int i = 0; i < N1; i++){

        int num = rand()%10+1;

        if(pthread_create(&escritor, NULL, (void*)suma, &num)!=0){
            perror("ERROR: al crear el hilo\n");
            printf("ERROR: al crear el hilo\n");
            exit(EXIT_FAILURE);
        }

        if(pthread_join(escritor, (void**)NULL)!=0){
            perror("ERROR: al crear la espera\n");
            printf("ERROR: al crear la espera\n");
            exit(EXIT_FAILURE);
        }
    }

     for(int i = 0; i < N1; i++){

        int num = rand()%10+1;

        if(pthread_create(&lector, NULL, (void*)resta, &num)!=0){
            perror("ERROR: al crear el hilo\n");
            printf("ERROR: al crear el hilo\n");
            exit(EXIT_FAILURE);
        }

        if(pthread_join(lector, (void**)NULL)!=0){
            perror("ERROR: al crear la espera\n");
            printf("ERROR: al crear la espera\n");
            exit(EXIT_FAILURE);
        }
    }

    if(pthread_mutex_destroy(&s)){
        perror("ERROR: a eliminar\n");
        printf("ERROR: a eliminar\n");
        exit(EXIT_FAILURE);
    }

    printf("La suma total: %d\n", variable);
    


    exit(EXIT_SUCCESS);
    
}
