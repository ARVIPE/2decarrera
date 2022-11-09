// SEMAFOROS BINARIOS (REALIZAR CONTROLES DE ERRORES DE TODO)
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
// 1) CREAR SEMAFOROS(VARIABLE GLOBAL)
pthread_mutex_t semaforo;

int main()
{
    // 2)INICIALIZAR SEMAFORO(INICIO DEL MAIN)
    pthread_mutex_init(&semaforo, NULL);
    // 3)CERRAR SEMAFORO (ANTES SECCIÓN CRÍTICA)
    pthread_mutex_lock(&semaforo);
    // 4)ABRIR SEMAFORO(DESPUÉS SECCIÓN CRÍTICA)
    pthread_mutex_unlock(&semaforo);
    // 5)ELIMINAR SEMAFORO(FINAL DEL MAIN)
    pthread_mutex_destroy(&semaforo);
}
