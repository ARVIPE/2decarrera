#include <sys/types.h> //Para tipo pid_t 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Para fork()
#include <errno.h>
#include <sys/wait.h>
#include <string.h> //Para la funcion strerror(), que permite describir el valor de errno como cadena.


int main(void) 
{
    pid_t pid, childpid;
    int status;
    
    pid = fork(); 
    switch(pid)
    {
        case -1:
			perror("fork error\n");
        	printf("errno value= %d\n", errno); 
			exit(EXIT_FAILURE); //Necesaria la librería <stdlib.h>  
            //return (-1);
            
        case 0: /* proceso hijo */
            printf("Soy el Hijo, mi PID es %d y el PPID de mi padre es %d \n", getpid(), getppid()); 
            exit(EXIT_SUCCESS);
            
        default: /* padre */
            printf("Soy el Padre, mi PID es %d y el PID de mi hijo es %d, el PPID de mi padre es %d\n", getpid(), pid, getppid());
			/*Averigue quien es el padre del proceso padre*/

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
            exit(EXIT_SUCCESS); //return 0;
    }
}


