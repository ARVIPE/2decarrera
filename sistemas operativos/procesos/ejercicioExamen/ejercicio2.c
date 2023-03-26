#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){

    pid_t child_pid, wpid;
    int status;


    child_pid = fork();
    if (child_pid == -1) {      /* fork() failed */
        perror("fork");
        exit(EXIT_FAILURE);
    }


    if (child_pid == 0) {       /* This is the child */
        printf("Soy el [HIJO] con id %ld y mi padre es %ld\n",(long int)getpid(), (long int)getppid());
        exit(getpid()%10);



    } else {                    /* This is the parent */
        do {
            wpid = waitpid(child_pid, &status, WUNTRACED
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