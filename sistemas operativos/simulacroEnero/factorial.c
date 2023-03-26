#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
	if(argc==1)
	{
		printf("Error en línea de argumentos, debe introducir un argumento obligatoriamente.\n");
		exit(EXIT_FAILURE);
	}

	int factorial = 1;

	for (int i = 1; i <= atoi(argv[1]); ++i)
	{
		factorial *= i;
	}

	printf("El factorial de %d es %d.\n", atoi(argv[1]), factorial);

	exit(EXIT_SUCCESS);
}
