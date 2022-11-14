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

int main()
{
    int array[3][3];
    int n = rand() % 10;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            array[i][j] = n;
        }
    }

    for(int k = 0; k < 3; k++){
        for(int m=0; m<3; m++){
            printf("%i\n", array[k][m]);
        }
    }

}