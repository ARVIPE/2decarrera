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
#include <stdbool.h>// Booleanos

struct param{
    int v[10];
    int pos;
};

void * functionHilo(struct param * p){
    if(p->pos%2 == 0){

    }else{

    }
}

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
    srand(time(NULL));
    pthread_t vhilos[10];
    struct param p[10];
    for(int i = 0; i < 10; i++){
        int n = rand()%10;
        for(int j = 0; j < 10; j++){
            p[j].v[i]=n;
        }
    }
    for(int i = 0; i < 10; i++){
        p[i].pos=i;
        pthread_create(&vhilos[i], NULL, (void*)functionHilo, &p[i]);
    }
}