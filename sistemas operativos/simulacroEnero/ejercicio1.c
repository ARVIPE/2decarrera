#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>



int main(int argc, char ** argv){
    pid_t child_pid, wpid, flag;
    int status;
    int N = atoi(argv[1]);
    int pid_hijo;

    for(int i = 0; i < N; i++){
        child_pid = fork();
        if (child_pid == -1) {      /* fork() failed */
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0) {       /* This is the child */
           if(i == N-1){
                printf("Soy el [HIJO] mi pid es %ld y mi padre es %ld\n", (long int)getpid(), (long int)getppid());
                exit(getpid()%10);
           }
        } else {                    
              while((flag=wait(&status))>0){
            if(WIFEXITED(status)){
                printf("hijo %ld finalizado con status %d\n",(long int)flag,WEXITSTATUS(status));
                pid_hijo=WEXITSTATUS(status);
            }
            else if(WIFSIGNALED(status)){
                printf("hijo %ld finalizado tras recibir una senal con status %d\n",(long int)flag,WTERMSIG(status));
            }
            else if(WIFSTOPPED(status)){
                printf("hijo %ld parado con status %d\n",(long int)flag,WSTOPSIG(status));
            }
            else if(WIFCONTINUED(status)){
                printf("hijo %ld reanudado\n",(long int)flag);
            }
             }





            int retorno = (getpid()%10) + pid_hijo;
            printf("Soy el [HIJO] mi pid es %ld y mi padre es %ld y retorno un %d\n", (long int)getpid(), (long int)getppid(), retorno);
            if(i == 0){
                exit(EXIT_SUCCESS);
            }else{
                exit(retorno);
            }

        }
         
    }
   
   
    exit(EXIT_SUCCESS);

}