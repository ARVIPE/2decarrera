// Ejercicio de examen

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

int main(void)
{
    pid_t pid, flag;
    int status, dato;
    pid = fork();
    if (pid == -1)
    {
        printf("Error");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        printf("Soy el proceso %ld y mi padre es %ld\n", (long int)getpid(), (long int)getppid());
        exit(getpid() % 10);
    }
    pid = fork();
    if (pid == -1)
    {
        printf("Error");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        printf("Soy el proceso %ld y mi padre es %ld\n", (long int)getpid(), (long int)getppid());
        pid = fork();
        if (pid == -1)
        {
            printf("Error");
            exit(EXIT_FAILURE);
        }
        else
        {
            if (pid == 0)
            {
                printf("Soy el proceso %ld y mi padre es %ld\n", (long int)getpid(), (long int)getppid());
                exit(getpid() % 10);
            }
        }
        pid = fork();
        if (pid == -1)
        {
            printf("Error");
            exit(EXIT_FAILURE);
        }
        else
        {
            if (pid == 0)
            {
                printf("Soy el proceso %ld y mi padre es %ld\n", (long int)getpid(), (long int)getppid());
                pid = fork();
                if (pid == -1)
                {
                    printf("Error");
                    exit(EXIT_FAILURE);
                }
                else if (pid == 0)
                {
                    printf("Soy el proceso %ld y mi padre es %ld\n", (long int)getpid(), (long int)getppid());
                    exit(getpid() % 10);
                }
               
                // espera bloqueante
                sleep(5);
                printf("[PADRE]: me pongo a esperar...\n");
                dato=0;
                while ((flag = wait(&status)) > 0)
                {
                    if (WIFEXITED(status))
                    {
                        dato += WEXITSTATUS(status);
                        printf("hijo %ld finalizado con status %d\n", (long int)flag, WEXITSTATUS(status));
                    }
                    else if (WIFSIGNALED(status))
                    {
                        printf("hijo %ld finalizado tras recibir una senal con status %d\n", (long int)flag, WTERMSIG(status));
                    }
                    else if (WIFSTOPPED(status))
                    {
                        printf("hijo %ld parado con status %d\n", (long int)flag, WSTOPSIG(status));
                    }
                    else if (WIFCONTINUED(status))
                    {
                        printf("hijo %ld reanudado\n", (long int)flag);
                    }
                }
                if (flag == (pid_t)-1 && errno == ECHILD)
                {
                    printf("Valor del errno= %d, definido como %s\n", errno, strerror(errno));
                }
                else
                {
                    printf("Error en la invocacion de wait o la llamada ha sido interrumpida por una se??al\n");
                    exit(EXIT_FAILURE);
                }
                exit(dato + (getpid() % 10));
                
            }
        }

        // espera bloqueante
        sleep(5);
        printf("[PADRE]: me pongo a esperar...\n");
        dato=0;
        while ((flag = wait(&status)) > 0)
        {
            if (WIFEXITED(status))
            {
                dato += WEXITSTATUS(status);
                printf("hijo %ld finalizado con status %d\n", (long int)flag, WEXITSTATUS(status));
            }
            else if (WIFSIGNALED(status))
            {
                printf("hijo %ld finalizado tras recibir una senal con status %d\n", (long int)flag, WTERMSIG(status));
            }
            else if (WIFSTOPPED(status))
            {
                printf("hijo %ld parado con status %d\n", (long int)flag, WSTOPSIG(status));
            }
            else if (WIFCONTINUED(status))
            {
                printf("hijo %ld reanudado\n", (long int)flag);
            }
        }
        if (flag == (pid_t)-1 && errno == ECHILD)
        {
            printf("Valor del errno= %d, definido como %s\n", errno, strerror(errno));
        }
        else
        {
            printf("Error en la invocacion de wait o la llamada ha sido interrumpida por una se??al\n");
            exit(EXIT_FAILURE);
        }
        exit(dato + (getpid() % 10));
    }

    // espera bloqueante
    sleep(5);
    printf("[PADRE]: me pongo a esperar...\n");
    dato=0;
    while ((flag = wait(&status)) > 0)
    {
        if (WIFEXITED(status))
        {
            dato += WEXITSTATUS(status);
            printf("hijo %ld finalizado con status %d\n", (long int)flag, WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status))
        {
            printf("hijo %ld finalizado tras recibir una senal con status %d\n", (long int)flag, WTERMSIG(status));
        }
        else if (WIFSTOPPED(status))
        {
            printf("hijo %ld parado con status %d\n", (long int)flag, WSTOPSIG(status));
        }
        else if (WIFCONTINUED(status))
        {
            printf("hijo %ld reanudado\n", (long int)flag);
        }
    }
    if (flag == (pid_t)-1 && errno == ECHILD)
    {
        printf("Valor del errno= %d, definido como %s\n", errno, strerror(errno));
    }
    else
    {
        printf("Error en la invocacion de wait o la llamada ha sido interrumpida por una se??al\n");
        exit(EXIT_FAILURE);
    }

    printf("El dato final es de : %i\n", dato+(getpid()%10));
    
    

    printf("[PADRE]: Me muero...\n");
    exit(EXIT_SUCCESS);
}