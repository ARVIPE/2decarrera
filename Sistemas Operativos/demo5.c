#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h> //Para la funcion strerror(), que permite describir el valor de errno como cadena.

/*Pruebe por ejemplo: 
./a.out tar -cf prueba.tar demo1 demo2 demoN 
donde file1 hasta fileN son ficheros que desea comprimir en el fichero prueba.tar
-Pruébelo también sin usar nada en la linea de argumentos.
-Por ultimo pruébelo usando un "file1" que no exista.
*/

int main(int argc, char **argv) 
{
	pid_t pid, childpid; 
	int status;

	pid = fork();
	switch(pid) 
	{
	  case -1: /* error del fork() */
        perror("fork error");
        printf("errno value= %d\n", errno); 
        exit(EXIT_FAILURE);

	  case 0: /* proceso hijo */
        printf("Proceso hijo con PID %d; mi padre con PPID %d\n", getpid(), getppid());
		        
        if (execvp(argv[1], &argv[1])<0) //Exec devuelve -1 en caso de error 
        {
           	perror("exec");
          	printf("errno value= %d\n", errno); 
		    exit(EXIT_FAILURE);
        }
        
	  default: /* padre */
        printf("Padre con pid: %ld\n", (long)getpid()); 

        //Se espera al hijo
        //Uso de wait(). No permite detectar la parada y reanudacion de procesos hijos: WIFSTOPPED(status), WIFCONTINUED(status)
        while ( (childpid=wait(&status)) > 0 ) 
        {
        if (WIFEXITED(status)) 
        {
           printf("Proceso padre %d, hijo con PID %ld finalizado, status = %d\n", getpid(), (long int)childpid, WEXITSTATUS(status));
        } 
        else if (WIFSIGNALED(status)) //Para seniales como las de finalizar o matar
        {
           printf("Proceso padre %d, hijo con PID %ld finalizado al recibir la señal %d\n", getpid(), (long int)childpid, WTERMSIG(status));
        } 
        }

        if (childpid==(pid_t)-1 && errno==ECHILD) //Entra cuando vuelve al while y no hay más hijos que esperar
        {
            printf("Proceso padre %d, no hay mas hijos que esperar. Valor de errno = %d, definido como: %s\n", getpid(), errno, strerror(errno));
        }	
        else
        {
            printf("Error en la invocacion de wait o waitpid. Valor de errno = %d, definido como: %s\n", errno, strerror(errno));
            exit(EXIT_FAILURE);
        }
	}
	printf("Programa finalizado\n");
	exit(EXIT_SUCCESS);
}