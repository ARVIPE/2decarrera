//Implementar un programa que reciba por linea de argumentos el numero de hilos a crear. Cada hilo debera de generar un numero aleatorio modulo 10 e imprimir.
//Soy el hilo, (identificador del hilo) y el numero aleatorio generado es tal... Ademas cada hilo debera retornar al proceso principal el numero aleatorio generado.
//Por ultimo el proceso principal, debera no solo imprimir el numero que recoge de cada hilo si no que ademas imprimirá la suma de todos ellos.
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <pthread.h> //Incluir esta libreria para hilos
#include <stdbool.h>// Booleanos

void * funcionHilo(){
    int n=rand()%10;
    printf("Soy el hilo %ld y he generado un %d\n", pthread_self(), n);
    //RETORNO
    int * retorno = (int*)malloc(sizeof(int));
    (*retorno)=n;
    pthread_exit((void*)retorno);
}

int main(int argc, char**argv){
    if(argc!=2){
        printf("Error...\n");
        exit(EXIT_FAILURE);
    }
    srand(time(NULL));
    int N = atoi(argv[1]);
    pthread_t idHilos[N];

    for(int i = 0; i < N; i++){
        if(pthread_create(&idHilos[i], NULL, (void*)funcionHilo, NULL)!=0){
            printf("ERROR...");
            exit(EXIT_FAILURE);
        }
    }

    int * valorRecogido;
    int suma = 0;
    for(int i = 0; i < N; i++){
        if(pthread_join(idHilos[i], (void**)&valorRecogido)!=0){
            printf("ERROR...");
            exit(EXIT_FAILURE);
        }
        printf("He recodigo un %d\n", (*valorRecogido));
        suma+=(*valorRecogido);
        free(valorRecogido);
    }
    printf("La suma es %d\n", suma);
    exit(EXIT_SUCCESS);

}