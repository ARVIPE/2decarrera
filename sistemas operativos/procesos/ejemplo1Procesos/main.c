#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

//Este programa crea un proceso que muestra un hola mundo
//Para ver el manual del fork (man fork)

//La función fork es la función que crea un proceso hijo, hace una clonación de mi proceso que imprime
//un hola mundo.

//El primer proceso padre es el llamado init

//Estados que se quedan a la espera de no volver al init debido a que su padre se ha muerto
//se llaman estados zombie. Todos los errores se recogen en el stderror.

//Un proceso hijo que pierde a su padre se queda a la espera de ser adoptado por otro proceso padre.


int main(){
    pid_t pid;
    pid = fork();
    printf("Hola mundo\n");
    printf("Soy el proceso %ld y mi padre es %ld\n",(long int)getpid(),(long int)getppid());
    return 0;
}

//Siempre que vayamos a crear un proceso debo:

/** 1) CREACIÓN
 * pid_t pid; (pid viene de process id) 
 * pid=fork();
 * ¿Que devuelve el fork en caso de que se cree o no un proceso hijo?
 *  -1 = ERROR
 *   0 = hijo
 *   >0 = padre (pid del hijo)
 */

/** 2) GESTIÓN
 *  if(pid == -1) {
 *      printf("Error.....");
 *      exit(EXIT_FAILURE);
 *  } else if(pid==0){
 *      printf("Soy el hijo \n");
 *      exit(EXIT_SUCCESS); 
 *  }else{
 *      printf("Soy el padre \n");
 *  }
 */


/**
 * Para identificar procesos 
 * printf("Soy el proceso %ld y mi padre es %ld\n",(long int)getpid(),(long int)getppid());
 * 
 */
















