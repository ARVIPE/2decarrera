//Implementar un programa que reciba por linea de argumentos el numero de hilos a crear. Cada hilo debera de generar un numero aleatorio modulo 10 e imprimir.
//Soy el hilo, (identificador del hilo) y el numero aleatorio generado es tal... Ademas cada hilo debera retornar al proceso principal el numero aleatorio generado.
//Por ultimo el proceso principal, debera no solo imprimir el numero que recoge de cada hilo si no que ademas imprimirá la suma de todos ellos.
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdio.h>
#include<errno.h>
#include<pthread.h>




int main(int argc, char ** argv){

    FILE * fich = fopen("fichero.txt", "w");
    

}