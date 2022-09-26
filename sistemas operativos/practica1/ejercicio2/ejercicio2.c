#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

int main(int argc, char ** argv){
    if(argc != 2){
        exit(EXIT_FAILURE);
    }
    pid_t pid;
    pid=fork();
        if(pid==-1){
                printf("Error");
                exit(EXIT_FAILURE);
        }else if(pid==0){
                printf("Soy el proceso %ld y mi padre es %ld\n",(long int)getpid(),(long int)getppid());
		    exit(EXIT_SUCCESS);
        }

    pid=fork();
        if(pid==-1){
                printf("Error");
                exit(EXIT_FAILURE);
        }else if(pid==0){
                printf("Soy el proceso %ld y mi padre es %ld\n",(long int)getpid(),(long int)getppid());
		    exit(EXIT_SUCCESS);
        }
    
  
}