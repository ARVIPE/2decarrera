#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>




int main(){
    
pid_t child_pid, wpid, flag;
int status, dato = 0;

for(int i = 0; i < 2; i++){


child_pid = fork();
if (child_pid == -1) {      /* fork() failed */
    perror("fork");
    exit(EXIT_FAILURE);
}

if (child_pid == 0) {
    if(i==0){
        printf("Soy el primer hijo mi pid es %ld y mi suma es %ld\n", (long int)getpid(), (long int)getpid()%10);  
        exit(getpid()%10);
    }else{

        for(int j = 0; j < 2; j++){
            child_pid = fork();
            if (child_pid == -1) {      /* fork() failed */
                perror("fork");
                exit(EXIT_FAILURE);
            }
            if (child_pid == 0) {
                if(j==0){
                    printf("Soy el primer nieto mi pid es %ld y mi suma es %ld\n", (long int)getpid(), (long int)dato+getpid()%10);  
                    exit(getpid()%10);
                }else{
                    printf("Soy el segundo nieto mi pid es %ld y mi suma es %ld\n", (long int)getpid(), (long int)dato+getpid()%10);
                    child_pid = fork();
                     if (child_pid == -1) {      /* fork() failed */
                        perror("fork");
                        exit(EXIT_FAILURE);
                    }
                    if(child_pid == 0){
                        printf("Soy el bisnieto mi pid es %ld y mi suma es %ld\n", (long int)getpid(), (long int)dato+getpid()%10);  
                        exit(getpid()%10);
                    }else{
                        while((flag=wait(&status))>0){
                            if (WIFEXITED(status)) {
                                printf("exited with pid %ld, status=%d\n", (long int)flag, WEXITSTATUS(status));
                                dato+=WEXITSTATUS(status);
                            } else if (WIFSIGNALED(status)) {
                                printf("killed by signal %d\n", WTERMSIG(status));
                            } else if (WIFSTOPPED(status)) {
                                printf("stopped by signal %d\n", WSTOPSIG(status));
                            } else if (WIFCONTINUED(status)) {
                                printf("continued\n");
                            }
                        };
                    }

                    exit(dato+getpid()%10);
                }
            }else{
                while((flag=wait(&status))>0){
                   if (WIFEXITED(status)) {
                       printf("exited with pid %ld, status=%d\n", (long int)flag, WEXITSTATUS(status));
                    dato+=WEXITSTATUS(status);
                   } else if (WIFSIGNALED(status)) {
                       printf("killed by signal %d\n", WTERMSIG(status));
                   } else if (WIFSTOPPED(status)) {
                       printf("stopped by signal %d\n", WSTOPSIG(status));
                   } else if (WIFCONTINUED(status)) {
                       printf("continued\n");
                   }
                };
                
            }

        }
        printf("Soy el segundo hijo mi pid es %ld y mi suma es %ld\n", (long int)getpid(), (long int)dato+getpid()%10);
        exit(dato+getpid()%10);
    }
   

} else {
    while((flag=wait(&status))>0){
                   if (WIFEXITED(status)) {
                       printf("exited with pid %ld, status=%d\n", (long int)flag, WEXITSTATUS(status));
                    dato+=WEXITSTATUS(status);
                   } else if (WIFSIGNALED(status)) {
                       printf("killed by signal %d\n", WTERMSIG(status));
                   } else if (WIFSTOPPED(status)) {
                       printf("stopped by signal %d\n", WSTOPSIG(status));
                   } else if (WIFCONTINUED(status)) {
                       printf("continued\n");
                   }
    };
               

}

}

 printf("Soy el padre %ld y mi suma es %ld\n", (long int)getpid(), (long int)getpid()%10);
 exit(EXIT_SUCCESS);

   
    

}
