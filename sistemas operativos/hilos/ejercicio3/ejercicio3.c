/* Implementar un programa que reciba por linea de argumentos tantos ficheros como uno quiera
   El programa debera crear tantos hilos como argumentos se hayan pasado, cada hilo debe imprimir el nombre del fichero que le haya tocado y el numero de lineas.*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <pthread.h>


void *ContarLineas(char * nombreFichero){
	FILE * fich = fopen(nombreFichero, "r");
	if(fich==NULL){
		printf("Error");
		exit(EXIT_FAILURE);
	}
	int cont = 0;
	char cadena[200];
	while(fgets(cadena,200,fich)){
		cont ++;
	}
	fclose(fich);
	printf("el nombre del fichero es %s y el numero de lineas es %d\n",nombreFichero,cont);
	pthread_exit((void*)NULL);
}

int main(int argc, char **argv){
	if(argc<2){
		printf("Error al recibir argumentos");
		exit(EXIT_FAILURE);
	}
	pthread_t id_hilo[argc-1];
	for(int i=0; i<(argc-1);i++){
		pthread_create(&id_hilo[i], NULL, (void*)ContarLineas,(void *)argv[i+1]);
		pthread_join(id_hilo[i],(void**)NULL);
	}
	for(int i=0; i<(argc-1);i++){
		pthread_join(id_hilo[i],(void**)NULL);
	}
	exit(EXIT_SUCCESS);
}