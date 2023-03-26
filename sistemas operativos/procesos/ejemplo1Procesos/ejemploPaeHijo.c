#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>


int main(){
    pid_t pid[2], wpid, pid_nieto;
    int status;

    for(int i = 0; i < 2; i++){

        pid[i]=fork();
    

        if(pid[i] == -1) //ERROR
        {
            printf("ERROR: en el fork\n");
            exit(EXIT_FAILURE);
        }else if(pid[i] == 0) //HIJO 
        {
            
            printf("[HIJO] soy el proceso hijo mi pid es: %ld y mi padre es: %ld\n", (long int)getpid(), (long int)getppid());
            if(i == 1){
                pid_nieto=fork();

                if(pid_nieto == -1){
                    printf("ERROR: en el fork\n");
                    exit(EXIT_FAILURE);
                }else if(pid_nieto == 0){
                    printf("[NIETO] soy el proceso nieto mi pid es: %ld y mi padre es: %ld\n", (long int)getpid(), (long int)getppid());
                    exit(EXIT_SUCCESS);
                }else{
                    //ESPERA
                    do {
                    wpid = waitpid(pid_nieto, &status, WUNTRACED
                    #ifdef WCONTINUED       /* Not all implementations support this */
                    | WCONTINUED
                    #endif
                    );
                    if (wpid == -1) {
                        perror("waitpid");
                        exit(EXIT_FAILURE);
                    }


                    if (WIFEXITED(status)) {
                        printf("child exited, status=%d\n", WEXITSTATUS(status));


                    } else if (WIFSIGNALED(status)) {
                        printf("child killed (signal %d)\n", WTERMSIG(status));


                    } else if (WIFSTOPPED(status)) {
                        printf("child stopped (signal %d)\n", WSTOPSIG(status));


                    #ifdef WIFCONTINUED     /* Not all implementations support this */
                    } else if (WIFCONTINUED(status)) {
                        printf("child continued\n");
                    #endif
                    } else {    /* Non-standard case -- may never happen */
                        printf("Unexpected status (0x%x)\n", status);
                    }
                    } while (!WIFEXITED(status) && !WIFSIGNALED(status));

                        }
                    }

            exit(EXIT_SUCCESS);
        }else{ //PADRE

            printf("[PADRE] soy el proceso padre y mi pid es: %ld\n", (long int)getpid());

            //ESPERA
            do {
            wpid = waitpid(pid[i], &status, WUNTRACED
            #ifdef WCONTINUED       /* Not all implementations support this */
            | WCONTINUED
            #endif
            );
            if (wpid == -1) {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }


            if (WIFEXITED(status)) {
                printf("child exited, status=%d\n", WEXITSTATUS(status));


            } else if (WIFSIGNALED(status)) {
                printf("child killed (signal %d)\n", WTERMSIG(status));


            } else if (WIFSTOPPED(status)) {
                printf("child stopped (signal %d)\n", WSTOPSIG(status));


            #ifdef WIFCONTINUED     /* Not all implementations support this */
            } else if (WIFCONTINUED(status)) {
                printf("child continued\n");
            #endif
            } else {    /* Non-standard case -- may never happen */
                printf("Unexpected status (0x%x)\n", status);
            }
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));

            
        }
    }
    printf("[PADRE]: Me muero...\n");
    exit(EXIT_SUCCESS);
}