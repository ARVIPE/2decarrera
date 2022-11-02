#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
void tratarsenal(int signal){
    printf("he recibido sigusr1 y su codigo es %d\n",signal);
    
}



int main(){
    pid_t pid,flag;
    int status,dato;
    pid=fork();

    //HIJO 1
    if(pid==-1){
        printf("error\n");
    }
    else if(pid==0){
        signal(SIGUSR1,&tratarsenal);
        printf("Soy el hijo:%ld,y mi padre es:%ld\n",(long int)getpid(),(long int)getppid());
        while(1);
    }
        
        for(int i=0;i<5;i++){
            sleep(1);
            kill(pid,SIGUSR1);
        }
        sleep(1);
        kill(pid,SIGKILL);
    while((flag=wait(&status))>0){
            if(WIFEXITED(status)){
                printf("hijo %ld finalizado con status %d\n",(long int)flag,WEXITSTATUS(status));
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
        exit(EXIT_SUCCESS);
    }