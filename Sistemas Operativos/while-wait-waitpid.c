/****************************************
Esquema de espera de hijos usando wait()
*****************************************/


/*Espera del padre a los hijos*/
while ((flag = wait(&valor)) > 0)
{
	if (WIFEXITED(valor)) 
	{
		printf("Hijo ID:%ld finalizado, estado=%d\n", (long int) flag, WEXITSTATUS(valor));
	} 
	else if (WIFSIGNALED(valor)) {  //Para seniales como las de finalizar o matar
		printf("Hijo  ID:%ld finalizado al recibir la señal %d\n", (long int) flag, WTERMSIG(valor));
	} 
}//while

if (flag==-1 && errno==ECHILD)
{
	printf("Proceso padre %d, no hay mas hijos que esperar. Valor de errno = %d, definido como: %s\n", getpid(), errno, strerror(errno));
	//perror("Valor de ernno usando perror"); //Descomente esta linea y compruebe su salida.
}
else
{
	printf("Error en la invocacion de wait o waitpid. Valor de errno = %d, definido como: %s\n", errno, strerror(errno));
	exit(EXIT_FAILURE);
}






/*****************************************
Esquema de espera de hijos usando  waitpid()
*****************************************/

while ( (flag=waitpid(-1,&status)) > 0 ) 
{
	if (WIFEXITED(status)) 
	{
		printf("Proceso padre %d, hijo con PID %ld finalizado, status = %d\n", getpid(), (long int)flag, WEXITSTATUS(status));
	} 
	else if (WIFSIGNALED(status)) //Para seniales como las de finalizar o matar
	{
		printf("Proceso padre %d, hijo con PID %ld finalizado al recibir la señal %d\n", getpid(), (long int)flag, WTERMSIG(status));
	} 
}
if (flag==(pid_t)-1 && errno==ECHILD) //Entra cuando vuelve al while y no hay más hijos que esperar
{
	printf("Proceso padre %d, no hay mas hijos que esperar. Valor de errno = %d, definido como: %s\n", getpid(), errno, strerror(errno));
}	
else
{
	printf("Error en la invocacion de wait o waitpid. Valor de errno = %d, definido como: %s\n", errno, strerror(errno));
	exit(EXIT_FAILURE);
}





/*****************************************
Esquema de espera de hijos usando  waitpid() con la posibilidad de capturar que un hijo sea parado y reanudado
*****************************************/


/*Espera del padre a los hijos*/
while ( (flag=waitpid(-1,&status,WUNTRACED | WCONTINUED)) > 0 ) 
{
    if (WIFEXITED(status)) 
    {
	    printf("Proceso Padre %d, hijo con PID %ld finalizado, status = %d\n", getpid(), (long int)flag, WEXITSTATUS(status));
    } 
    else if (WIFSIGNALED(status))  
    {
	    printf("Proceso Padre %d, hijo con PID %ld finalizado al recibir la señal %d\n", getpid(), (long int)flag, WTERMSIG(status));
    } 
    else if (WIFSTOPPED(status))  //Para cuando se para un proceso. Con wait() no nos serviria.
    {
	    printf("Proceso Padre %d, hijo con PID %ld parado al recibir la señal %d\n", getpid(), (long int)flag,WSTOPSIG(status));
    } 
    else if (WIFCONTINUED(status))  //Para cuando se reanuda un proceso parado. Con wait() no nos serviria.
    {
	    printf("Proceso Padre %d, hijo con PID %ld reanudado\n", getpid(), (long int) flag);		  
    }
}//while

if (flag==(pid_t)-1 && errno==ECHILD)
{
    printf("Proceso Padre %d, no hay mas hijos que esperar. Valor de errno = %d, definido como: %s\n", getpid(), errno, strerror(errno));
}
else
{
    printf("Error en la invocacion de wait o waitpid. Valor de errno = %d, definido como: %s\n", errno, strerror(errno));
    exit(EXIT_FAILURE);
}	


