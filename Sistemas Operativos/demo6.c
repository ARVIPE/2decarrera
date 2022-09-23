#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> //Para la funcion strerror(), que permite describir el valor de errno como cadena.

int main()
{

    pid_t idProceso, childpid;
    int status;
    /* Variable para comprobar que se copia inicialmente en cada proceso y
	 que luego puede cambiarse independientemente en cada uno de ellos. */
    int variable = 1;

    idProceso = fork();
    if (idProceso == -1)
    {
		perror("fork error");
		printf("errno value= %d\n", errno); 
		exit(EXIT_FAILURE);
    }
    else if (idProceso == 0)
    {
		/* El hijo escribe su pid en pantalla y el valor de variable */
		printf ("Hijo: Mi pid es %d. El pid de mi padre es %d\n", getpid(), getppid());
		
		/* Escribe valor de variable y la cambia */
		printf ("Hijo: variable = %d. La cambio por variable = 2\n", variable); 
		variable = 2;
		
		/* Espera 5 segundos, saca en pantalla el valor de variable y sale */ 
		/*OJO, ESTOS SLEEPS SON A MODO DIVULGATIVO. NO USAR SLEEPS PARA SINCRONIZAR SUS PROCESOS*/
		sleep (5);
		printf ("Hijo: variable = %d y salgo\n", variable);
		
		exit (33);
    }
    else //Padre
    {
		/* Espera un segundo (para dar tiempo al hijo a hacer sus cosas y no entremezclar salida en la pantalla) y escribe su pid y el de su hijo */
		/*OJO, ESTOS SLEEPS SON A MODO DIVULGATIVO. NO USAR SLEEPS PARA SINCRONIZAR SUS PROCESOS*/
		sleep (1);
		printf ("Padre: Mi pid es %d. El pid de mi hijo es %d\n",getpid(), idProceso);
		
	
      /*Espera del padre a los hijos*/
      while ( (childpid=waitpid(-1,&status,WUNTRACED | WCONTINUED)) > 0 ) 
      {
          if (WIFEXITED(status)) 
          {
             printf("Proceso Padre %d, hijo con PID %ld finalizado, status = %d\n", getpid(), (long int)childpid, WEXITSTATUS(status));
          } 
          else if (WIFSIGNALED(status))  
          {
             printf("Proceso Padre %d, hijo con PID %ld finalizado al recibir la señal %d\n", getpid(), (long int)childpid, WTERMSIG(status));
          } 
          else if (WIFSTOPPED(status))  //Para cuando se para un proceso. Con wait() no nos serviria.
          {
             printf("Proceso Padre %d, hijo con PID %ld parado al recibir la señal %d\n", getpid(), (long int)childpid,WSTOPSIG(status));
          } 
          else if (WIFCONTINUED(status))  //Para cuando se reanuda un proceso parado. Con wait() no nos serviria.
          {
             printf("Proceso Padre %d, hijo con PID %ld reanudado\n", getpid(), (long int) childpid);		  
          }
      }//while

      if (childpid==(pid_t)-1 && errno==ECHILD)
      {
          printf("Proceso Padre %d, no hay mas hijos que esperar. Valor de errno = %d, definido como: %s\n", getpid(), errno, strerror(errno));
      }
      else
      {
          printf("Error en la invocacion de wait o waitpid. Valor de errno = %d, definido como: %s\n", errno, strerror(errno));
          exit(EXIT_FAILURE);
      }	 
    }
	 exit(EXIT_SUCCESS);
}
