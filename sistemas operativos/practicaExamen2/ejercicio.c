// Ejercicio que crea tantos procesos en función del número de ficheros pasados cuenta lineas de estos ficheros y devuelve la suma total de las lineas

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

int contarLineas(char *nF)
{
    FILE *fich = fopen(nF, "r");
    if (fich == NULL)
    {
        printf("Error...");
        exit(EXIT_FAILURE);
    }
    int cont = 0;
    char cadena[200];
    while (fgets(cadena, 200, fich))
    {
        cont++;
    }
    fclose(fich);
    return cont;
}


int main(int argc, char **argv)
{
    pid_t pid, flag;
    int status;
    if (argc < 2)
    {
        printf("ERROR: tienes que pasarle al menos un fichero\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < (argc - 1); i++)
    {
        pid = fork();
        if (pid == -1)
        {
            printf("Error");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            printf("Soy el proceso %ld y mi padre es %ld\n", (long int)getpid(), (long int)getppid());
            int cont = contarLineas(argv[i+1]);
            exit(cont);
        }
    }
    // espera bloqueante
    printf("[PADRE]: me pongo a esperar...\n");
    int dato = 0;
    int i=0;
    while ((flag = wait(&status)) > 0)
    {
        if (WIFEXITED(status))
        {   dato += WEXITSTATUS(status);
            printf("El fichero %s tiene %d lineas\n",argv[i+1],WEXITSTATUS(status));
            i++;
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
        printf("Error en la invocacion de wait o la llamada ha sido interrumpida por una señal\n");
        exit(EXIT_FAILURE);
    }

    printf("Suma de lineas totales %i \n", dato);
    exit(EXIT_SUCCESS);
}
