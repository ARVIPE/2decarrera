// Realice la multiplicación en paralelo de una matriz de 3x3 por un vector de 3x1.
// Para ello cree tres hebras que se repartan las filas de la matriz y del vector.
// Cada hijo debe imprimir la fila que le ha tocado y el resultado final de la multiplicación la cual además envía al padre.
// El padre debe esperar por la terminación de cada hijo y mostrar el vector resultante.
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <pthread.h> //Incluir esta libreria para hilos
#include <stdbool.h> // Booleanos


void * funcion(struct param * p){
    int resultado=0;
    for(int i = 0; i < 3; i++){
        resultado += (p->m1[p->fila][i] * p->m2[i]);
    }
    int * retorno = (int*)malloc(sizeof(int));
    (*retorno) = resultado;
    pthread_exit((void*)retorno);
}

struct param
{
    int n1[3][3];
    int n2[3];
    int fila;
};

int main()
{
    struct param p[3];
    int * recogido;
    int resultado[3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int n = rand() % 10;
            for (int k = 0; k < 3; k++)
            {
                p[k].m[i][j] = n;
                for (int i = 0; i < 3; i++)
                {
                    p[i].fila = i;
                    if (pthread_create(&idhilos[i], NULL, (void *)funcion, &p[i]) != 0)
                    {
                        
                    }
                    resultado[i]=(*recogido);
                    free(recogido);
                }
            }
        }
    }
}