// Crear un vector aleatorio de tam 10 rellenado con los numeros que nos de la gana. Luego creamos 10 hilos, los de creación par deberan de comprobar si el numero
// situado en su posición es primo o no. Mientras que los hilos de creación impar deberan de comprobar si es perfecto o no.
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <pthread.h> //Incluir esta libreria para hilos
#include <stdbool.h> // Booleanos

struct param
{
    int v[10];
    int pos;
};

bool esPrimo(int num){
    int contador = 0;
    for(int i = 1; i <= num; i++){
        if(num%i==0){
            contador++;
        }
    }
    if(contador > 2 && num!=0 && num!=1){
        return true;
    }else{
        return false;
    }
}

bool esPerfecto(int num){
    int perfecto = 0;

    for(int i = 1; i < num; i++){
        if(num%i==0){
            perfecto+=i;
        }
    }

    if(perfecto==num){
        return true;
    }else{
        return false;
    }

}

void *functionHilo(struct param *p)
{
    bool valor;
    int num = p->v[p->pos];
  
    if(p->pos%2==0){
        if(esPrimo(num)==true){
            printf("El numero en la posición %i es el numero %i y no es primo\n", p->pos, num);
        }else{
            printf("El numero en la posición %i es el numero %i y es primo\n", p->pos, num);
        }
    }else{
        if(esPerfecto(num)==true){
            printf("El numero en la posición %i es el numero %i es perfecto\n", p->pos, num);
        }else{
            printf("El numero en la posición %i es el numero %i no es perfecto\n", p->pos, num);
        }
    }

    pthread_exit((void *)NULL);
}



int main()
{
    srand(time(NULL));
    pthread_t vhilos[10];
    struct param p[10];
    for (int i = 0; i < 10; i++)
    {
        int n = rand() % 10;
        for (int j = 0; j < 10; j++)
        {
            p[j].v[i] = n;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        p[i].pos = i;
        pthread_create(&vhilos[i], NULL, (void *)functionHilo, &p[i]);
        pthread_join(vhilos[i], (void **)NULL);   
    }

     
  
}