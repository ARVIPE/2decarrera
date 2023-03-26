#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <pthread.h>

pthread_mutex_t semaforo;

void * cliente(int pos){

pthread_mutex_lock(&semaforo);
printf("%d", pos);
pthread_mutex_unlock(&semaforo);



pthread_exit((void*)NULL);
}


int main(int argc, char ** argv){

pthread_mutex_init(&semaforo, NULL);
int n = atoi(argv[2]);

pthread_t hilo_cliente[n];

if(argc != 3){
    printf("ERROR: no se han introducido suficientes argumentos");
    perror("ERROR: no se han introducido suficientes argumentos");
    exit(EXIT_FAILURE);
}

int * cantidad_modelos_camisetas;
cantidad_modelos_camisetas = (int*)malloc(n * sizeof(int));

srand(time(NULL));

for(int i = 0; i < atoi(argv[1]); i++){
    if(pthread_create(&hilo_cliente[i], NULL, (void*)cliente, &i)!=0){
        printf("ERROR: al crear el cliente");
        perror("ERROR: al crear el cliente");
        exit(EXIT_FAILURE);
    }
}


for(int i = 0; i < atoi(argv[1]); i++){
    pthread_join(hilo_cliente[i], (void**)NULL);
}

pthread_mutex_destroy(&semaforo);

}