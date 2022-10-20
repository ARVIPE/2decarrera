//Programa que duerme 30 sg señal que se corta con control c 
//Muere el proceso
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

int main(){
    printf("Me duermo 30 segundos...\n");
    sleep(30);
    exit(EXIT_SUCCESS);
}

//sigint es matar el proceso. Básicamente control c. (Señal asincrona porque no sabemos en que momennto se va a cortar el proceso)
//La señal la administra la CPU

