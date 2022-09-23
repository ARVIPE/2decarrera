#include <sys/types.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h>
#include <sys/wait.h>
#include <string.h> //Para la funcion strerror(), que permite describir el valor de errno como cadena.

int main () 
{
    int i, j, status; 
    pid_t rf, childpid;

    rf = fork(); 
    switch (rf) 
    {
        case -1:
        
            perror("fork error");
            printf("errno value= %d\n", errno); 
            exit(EXIT_FAILURE);

        case 0:

            i = 0;

            printf("Soy el hijo, mi PID es %d y mi variable i (inicialmente a %d) es:\n",getpid( ),i);

            for (j=0; j<5; j++)
            {
              i++;
              i++;
              printf ("Soy el hijo, mi variable i es %d\n", i);
            }
            
            break; 

        default:
        
            i = 0;

            printf("Soy el padre, mi PID es %d y mi variable i (inicialmente a %d) es:\n", getpid( ), i);

            for (j=0; j<5; j++) 
            {
                i++;
                i++;
                printf ("Soy el padre, mi variable i es %d\n", i);
            }
                  
             //Se espera al hijo
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
    }//switch
            
    //Esta linea la ejecuta tanto el padre como el hijo 
    printf ("Final de ejecucion...\n"); 
    exit(EXIT_SUCCESS);
}
