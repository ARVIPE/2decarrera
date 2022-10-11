#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Error no se ha introducido número");
        exit(EXIT_FAILURE);
    }

    int factorial = 1;
    int tam = atoi(argv[1]);
    for(int i = 0; i < tam; i++){
        factorial += factorial*i;
    }
    return factorial;
}