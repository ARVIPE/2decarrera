#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void * error(){
    int num = 3;
    num = num/0;
    printf("Soy el hilo %ld\n", pthread_self());
    pthread_exit((void*)NULL);
}

void * noError(){
    printf("Soy el hilo %ld\n", pthread_self());
    pthread_exit((void*)NULL);
}

int main(){


    pthread_t idhilo, idhiloRes;

    pthread_create(&idhilo, NULL, (void*)error, NULL);

    pthread_create(&idhiloRes, NULL, (void*)noError, NULL);

    pthread_join(idhilo, (void**)NULL);


    pthread_join(idhiloRes, (void**)NULL);

}