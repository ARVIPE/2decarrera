#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

int main(int argc, char ** argv){
    int pid = atoi(argv[1]);
    printf("Enviando señal SIGUSR1 a %d ...\n", pid);
    kill(pid, SIGUSR1);
    exit(EXIT_SUCCESS);
}