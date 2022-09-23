#include <sys/types.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <errno.h>
#include <sys/wait.h>


int main(void) 
{
    pid_t hijo_pid, childpid; 
    int status;
    
    hijo_pid= fork(); 
    
    if (hijo_pid == -1) 
    {
      perror("fork error");
      printf("errno value= %d\n", errno); 
      exit(EXIT_FAILURE);
    }
    else if (hijo_pid == 0) //hijo
    {
      printf("Hijo con pid: %d\n", getpid());
      exit(EXIT_SUCCESS); 
    }
    else /* padre */ 
    {
      printf("Padre con pid: %d\n", getpid()); 

      childpid=wait(&status);

      if(childpid>0)
      {
        if (WIFEXITED(status)) 
        {
            printf("Hijo %d recogido, status=%d\n",childpid, WEXITSTATUS(status));
        } 
        else if (WIFSIGNALED(status)) 
        {
            printf("Hijo %d matado (signal %d)\n", childpid, WTERMSIG(status));
        } 
      }
      else 
      {
         printf("Error en la invocacion de wait o la llamada ha sido interrumpida por una señal.\n");
         exit(EXIT_FAILURE);
      } 
      exit(EXIT_SUCCESS); //return 0; 
   }
}