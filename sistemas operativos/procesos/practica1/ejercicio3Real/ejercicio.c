#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv)
{

    if (argc !=3)
    {
        printf("error en linea de argumentos\n");
        exit(EXIT_FAILURE);
    }
    pid_t pid, wpid,child_pid, flag;
    int status;
    for(int i=0;i<2;i++){
        child_pid=fork();
        if(pid==-1){
            printf("error\n");
            exit(EXIT_FAILURE);

        }
        else if(child_pid==0){
            if(i==0){
                execlp(argv[1],argv[1],NULL);
            }
            else{
                execlp(argv[2],argv[2],NULL);
            }
            exit(EXIT_SUCCESS);
        }
    }

        while((flag=wait(&status))>0){
            if (WIFEXITED(status)) {
                       printf("exited %ld, status=%d\n", (long int)flag, WEXITSTATUS(status));
                   } else if (WIFSIGNALED(status)) {
                       printf("killed by signal %d\n", WTERMSIG(status));
                   } else if (WIFSTOPPED(status)) {
                       printf("stopped by signal %d\n", WSTOPSIG(status));
                   } else if (WIFCONTINUED(status)) {
                       printf("continued\n");
                   }
        }

             





    
    exit(EXIT_SUCCESS);
}