#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

// IMPLEMENTAR AQUÍ LA FUNCIÓN MANEJADORA
void tratarsenal(int signal)
{
    printf("Soy el hijo %ld, senial %d recibida\n", (long int)getpid(),signal);
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        printf("Error en línea de argumentos, debe introducir obligatoriamente 3 argumentos.\n");
        printf("Ejemplo de ejecución: %s 3 factorial 5\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pid_t pid, flag;
    int status;

   
    pid = fork();

    switch (pid)
    {
    // COMPLETAR
    case -1:
        printf("error");
        exit(EXIT_FAILURE);

    case 0:
        signal(SIGUSR1, &tratarsenal);
        printf("Soy el hijo %ld, espero seniales y mi padre es %ld\n", (long int)getpid(), (long int)getppid());
        
        while (1){
            printf("Soy el hijo %ld, imprimiendo una vez por segundo...\n", (long int)getpid());
            sleep(1);
        };

    default:
        for (int i = 0; i < atoi(argv[1]); i++)
        {
            printf("Soy el proceso padre %ld, esperando 3 segundos para enviar senial...\n", (long int)getpid());
            sleep(3);
            kill(pid, SIGUSR1);
        }
        sleep(1);
        kill(pid, SIGKILL);
    }



    pid = fork();
    
    switch (pid)
    {
    case -1:
        printf("error");
        break;
    case 0:
            printf("Soy el hijo %ld que calculo factoriales y mi padre es:%ld\n", (long int)getpid(), (long int)getppid());
            execvp("./factorial", &argv[3 - 1]);
            exit(EXIT_SUCCESS);
    }

   
    while ((flag = wait(&status)) > 0)
    {
        if (WIFEXITED(status))
        {
            printf("Proceso Padre, Hijo con PID %ld finalizado, estado = %d\n", (long int)flag, WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status))
        { // Para seniales como las de finalizar o matar
            printf("Proceso Padre, Hijo con PID %ld finalizado al recibir la señal %d\n", (long int)flag, WTERMSIG(status));
        }
        else if (WIFSTOPPED(status))
        { // Para cuando se para un proceso. Al usar wait() en vez de waitpid() no nos sirve.
            printf("Proceso Padre, Hijo con PID %ld parado al recibir la señal %d\n", (long int)flag, WSTOPSIG(status));
        }
        else if (WIFCONTINUED(status))
        { // Para cuando se reanuda un proceso parado. Al usar wait() en vez de waitpid() no nos sirve.
            printf("Proceso Padre, Hijo con PID %ld reanudado\n", (long int)flag);
        }
    }
    if (flag == (pid_t)-1 && errno == ECHILD)
    {
        printf("Proceso Padre, valor de errno = %d, definido como: %s\n", errno, strerror(errno));
    }
    else
    {
        printf("Error en la invocacion de wait o la llamada ha sido interrumpida por una señal.\n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}