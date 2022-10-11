#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include "factorial.c"

int main(int argc, char *argv[])
{
    pid_t pid, flag;
    int status;
    for (int i = 0; i <= 2; i++)
    {
        pid=fork();
        
    }
}
