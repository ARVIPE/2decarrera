#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>


int main(int argc, char const *argv [])
{
    int tam = atoi(argv[1]);
    if (tam < 2)
    {
        printf("Error no se ha introducido número");
        exit(EXIT_FAILURE);
    }
    int factorial = 1;
    
    for (int i = 0; i < tam; i++)
    {
        factorial += factorial * i;
    }
    printf("El factorial de %i es %i\n", tam, factorial);
}
