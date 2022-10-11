#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv){
	if(argc<4){
		printf("Error al recibir argumentos");
		exit(EXIT_FAILURE);
	}

	pid_t pid, flag;
	int status;

	printf("[PADRE]Soy el proceso %ld y mi padre es %ld\n",(long int)getpid(),(long int)getppid());
	for(int i=0; i<2;i++){
		pid = fork();
		if(pid == -1){ //ERROR
		printf("Error en el fork()\n");
		exit(EXIT_FAILURE);
		}
		else if(pid == 0) //HIJO
		{
			printf("[HIJO]: Soy el proceso hijo y mi pid es %ld y el padre %ld\n",(long int)getpid(),(long int)getppid()); 
			if(i==0){
				execlp(argv[1],argv[1],NULL);	
			}
			else{
				execvp(argv[2],&argv[3-1]);
			}
		exit(EXIT_SUCCESS);
		} 
	}
	while((flag=wait(&status))>0){
		    if(WIFEXITED(status)){
		        printf("hijo %ld finalizado con status %d\n",(long int)pid,WEXITSTATUS(status));
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
		if(flag==(pid_t)-1 && errno==ECHILD){ 
		    printf("Valor del errno= %d, definido como %s\n",errno,strerror(errno));
		}
		else{
		    printf("Error en la invocacion de wait o la llamada ha sido interrumpida por una señal\n");
		    exit(EXIT_FAILURE);
		}
	 	exit(EXIT_SUCCESS);
	}