#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>

void tratarSenar(int signal){
    printf("He recibido la señal de tipo sigurs y la señal recibida tiene el codigo %d\n", signal);
}

int main(int argc, char ** argv){

    if(argc !=4){
        perror("ERROR: no se han introducido suficientes argumentos");
        printf("ERROR: no se han introducido suficientes argumentos");
        exit(EXIT_FAILURE);
    }


    pid_t child_pid, wpid, flag;
    int status;


    for(int i = 0; i < 2; i++){
        child_pid = fork();
        if (child_pid == -1) {      /* fork() failed */
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0) {       /* This is the child */
            if(i == 0){
                printf("[HIJO] mi pid es %ld, el de mi padre es %ld\n", (long int)getpid(), (long int)getppid());
                exit(EXIT_SUCCESS);

            }else{
                //int n = atoi(argv[3]);
                execvp(argv[2], &argv[3-1]);
            }


            exit(EXIT_SUCCESS);
        } else {                    /* This is the parent */
            while((flag=wait(&status))>0){
                        if (WIFEXITED(status)) {
                            printf("exited with pid %ld, status=%d\n", (long int)flag, WEXITSTATUS(status));
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

    child_pid = fork();
        if (child_pid == -1) {      /* fork() failed */
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0) {       /* This is the child */
                signal(SIGUSR1,&tratarSenar);
                printf("[HIJO] mi pid es %ld, el de mi padre es %ld\n", (long int)getpid(), (long int)getppid());
                while(1);
        } else {  
            
            for(int i = 0; i < atoi(argv[3]); i++){
                sleep(1);
                kill(child_pid, SIGUSR1);
            }
            sleep(1);
            kill(child_pid, SIGKILL);


            while((flag=wait(&status))>0){
                        if (WIFEXITED(status)) {
                            printf("exited with pid %ld, status=%d\n", (long int)flag, WEXITSTATUS(status));
                        } else if (WIFSIGNALED(status)) {
                            printf("killed by signal %d\n", WTERMSIG(status));
                        } else if (WIFSTOPPED(status)) {
                            printf("stopped by signal %d\n", WSTOPSIG(status));
                        } else if (WIFCONTINUED(status)) {
                            printf("continued\n");
                        }
            };
        }

    exit(EXIT_SUCCESS);
}