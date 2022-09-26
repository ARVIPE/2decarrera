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
    for(int i = 0; i<atoi(argv[1]); i++){
        pid=fork();
        if(pid==-1){
            printf("Error");
            exit(EXIT_FAILURE);
        }else if(pid==0){
            //Tenemos que poner este exit porque si no va a seguir creando hijos dentro del primer hijo
            //cuando llegue al segundo hijo
           printf("Soy el proceso %ld y mi padre es %ld\n",(long int)getpid(),(long int)getppid());
		   exit(EXIT_SUCCESS);
        }
    }
    exit(EXIT_SUCCESS);
}