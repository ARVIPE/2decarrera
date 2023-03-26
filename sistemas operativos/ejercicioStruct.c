//./a.out 10 4 
// Crear un programa al que haya que introducir dos argumentos. Que por un lado cree tantos hilos como argumentos tenemos y realiza suma con el primero
// y con el segundo reste
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <pthread.h>

struct param{
    int prim;
    int segun;
};

void * suma(struct param *p){

    int numero = p->prim + p->segun;
    int * retorno = (int*)malloc(sizeof(int));
    *retorno = numero;
    pthread_exit((void*)retorno);
}

int main(int argc, char **argv){
    if(argc!=3){
        printf("ERROR\n");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    int N1= atoi(argv[1]);
    struct param s[N1];

    pthread_t idhilo[N1];

    for(int i = 0; i < N1; i++){
        s[i].prim = rand() % 10;
        s[i].segun = rand()%10;


        pthread_create(&idhilo[i], NULL, (void*)suma, &s[i]);
    }
    
    int * valorRecogido;
    for(int i = 0; i < N1; i++){
        pthread_join(idhilo[i], (void**)&valorRecogido);

        printf("El valor es: %i\n", *valorRecogido);
        free(valorRecogido);

    }


    exit(EXIT_SUCCESS);




}