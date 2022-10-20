#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <signal.h> //Metemos esta libreria
//TRATAMIENTO DE LA SEÑAL
//Ejemplo primer de signal
//1) Argumento señal a tratar (SIEMPRE EN MAYUSCULA)
//2) Argumento & nombre de la función &función manejadora

//Todas las funciones manejadoras tienen que recoger un numero entero que equivale a la señal

void recibo(int signal){
    printf("Se ha recibido la señal Ctrl + C\n");
}

int main(){
    signal(SIGINT,&recibo);
    printf("Me duermo 30 segundos...\n");
    sleep(30);
    exit(EXIT_SUCCESS);
}