//./a.out 10 4 
// Crear un programa al que haya que introducir dos argumentos. Que por un lado cree tantos hilos como argumentos tenemos y realiza suma con el primero
// y con el segundo reste
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
    int prim;
    int segun;
};

void * suma(struct param *p){
    int numero = p->prim + p->segun;
    int * retorno=(int*)malloc(sizeof(int));
    (*retorno)=numero;
    pthread_exit((void*)retorno);

}

void * resta(struct param *p){
    int numero = p->prim - p->segun;
    int * retorno=(int*)malloc(sizeof(int));
    (*retorno)=numero;
    pthread_exit((void*)retorno);
}


int main(int argc, char **argv){
    if(argc!=3){
        printf("Error...\n");
        exit(EXIT_FAILURE);
    }
    srand(time(NULL));
    int N1 = atoi(argv[1]); 
    int N2 = atoi(argv[2]);
    struct param s[N1];
    struct param r[N2];
    pthread_t id_hiloSum[N1], id_hiloRes[N2];

    for(int i = 0; i < N1; i++){
        s[i].prim = rand() % 10;
        s[i].segun = rand() % 10;

        if(pthread_create(&id_hiloSum[i], NULL, (void*)suma, &s[i])!=0){
            printf("ERROR...");
            exit(EXIT_FAILURE);
        }

    }

    for(int i = 0; i < N2; i++){
        r[i].prim = rand() % 10;
        r[i].segun = rand() % 10;

        if(pthread_create(&id_hiloRes[i], NULL, (void*)resta, &r[i])!=0){
            printf("ERROR...");
            exit(EXIT_FAILURE);
        }

    }


    int * valorRecogido;
    for(int i = 0; i < N1; i++){
        if(pthread_join(id_hiloSum[i], (void**)&valorRecogido)!=0){
            printf("ERROR...");
            exit(EXIT_FAILURE);
        }
        printf("Soy el hilo %i sumo los valores %i, %i y la suma es de %d\n", i, s[i].prim, s[i].segun, (*valorRecogido));
        free(valorRecogido);
    }

  
    for(int i = 0; i < N2; i++){
        if(pthread_join(id_hiloRes[i], (void**)&valorRecogido)!=0){
            printf("ERROR...");
            exit(EXIT_FAILURE);
        }
        printf("Soy el hilo %i resto los valores %i, %i y la resto es de %d\n", i, r[i].prim, r[i].segun, (*valorRecogido));
        free(valorRecogido);
    }

    
    
    
}




