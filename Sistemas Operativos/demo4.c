#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h> //Para la funcion strerror(), que permite describir el valor de errno como cadena.

void main(void)
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

            if(execlp("ls","ls","-l",NULL)==-1)
            {
	            perror("Falla en la ejecucion exec de ls -l");
	            printf("errno value= %d\n", errno);
	            exit(EXIT_FAILURE);
            }
		
	     
		default: /* padre */
            printf("Proceso padre con pid %d\n", getpid());

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
	}//switch
	
	
	//La ejecutará en este caso solo el padre, el hijo tiene una 	llamada a exec()
	printf("Fin del programa. PID del que ejecuta esta linea: %d\n", getpid());
	exit(EXIT_SUCCESS);
}