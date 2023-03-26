//./a.out 10 4 
// Crear un programa al que haya que introducir dos argumentos. Que por un lado cree tantos hilos como argumentos tenemos y realiza suma con el primero
// y con el segundo reste

#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <time.h>


struct param{
    int prim;
    int segund;
};

void * suma(struct param *p){
    int suma2 = p->prim + p->segund;
    int * retorno = (int*)malloc(sizeof(int));
    *retorno = suma2;

    pthread_exit((void*)retorno);

}

void * resta(struct param *r){
    int resta2 = r->prim - r->segund;
    int * retorno = (int*)malloc(sizeof(int));
    *retorno = resta2;

    pthread_exit((void*)retorno);

}


int main(int argc, char ** argv){

    if(argc!=3){
        perror("ERROR: no se han introducido suficientes argumentos\n");
        printf("ERROR: no se han introducido suficientes argumentos\n");
        exit(EXIT_FAILURE);
    }

    int N1 = atoi(argv[1]);
    int N2 = atoi(argv[2]);
    srand(time(NULL));

    pthread_t idhilo[N1], idhiloRes[N2];
    struct param p[N1];
    struct param r[N2];

    for(int i = 0; i < N1; i++){
        p[i].prim = rand()%10;
        p[i].segund = rand()%10;

        pthread_create(&idhilo[i], NULL, (void*)suma, &p[i]);
    }

    for(int i = 0; i < N2; i++){
        r[i].prim = rand()%10;
        r[i].segund = rand()%10;

        pthread_create(&idhiloRes[i], NULL, (void*)resta, &r[i]);
    }    

    int * valorRecogido;
    for(int i = 0; i < N1; i++){
        pthread_join(idhilo[i], (void**)&valorRecogido);
        printf("El valor recogido es: %d\n", *valorRecogido);
        free(valorRecogido);
    }

     for(int i = 0; i < N2; i++){
        pthread_join(idhiloRes[i], (void**)&valorRecogido);
        printf("El valor recogido es: %d\n", *valorRecogido);
        free(valorRecogido);
    }


}