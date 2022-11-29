//Tenemos un buffer de 0-5 e inicializar con numeros aleatorios entre 0-19

//Hay que crear tantos hilos productores como hilos consumidores como se indiquen por
//linea de argumentos. (Primer argumento productor, segundo argumento consumidor).

//Genera una posición aleatoria mod5, una cantidad aleatoria mod10 y lo que hace es que en esa posición genere esa cantidad.

//Y en esa posición mete o saca en función de si es productor o consumidor.

//El main tiene que acabar imprimiendo cual ha sido la cantidad total producida y consumida.

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

int v[5];

void inicializarVector(){
    for(int i = 0; i < 5; i++){
        v[i]=rand()%20;
    }
}


int main(int * argc, char ** argv){
    if(argc!=3){
        printf("ERROR: no se han introducido suficientes argumentos\n");
        exit(EXIT_FAILURE);
    }
    srand(time(NULL));
}