#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

void tratarSenal(int signal)
{
    printf("He recibido SIGSUR y su codi es %d\n", signal);
}

int main()
{
    signal(SIGUSR1, &tratarSenal);
    printf("Soy %ld \n",(long int)getpid());
    while(1);
    exit(EXIT_SUCCESS);
}