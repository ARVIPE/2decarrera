//DECLARAMOS ESTA LIBRERIA
#include <semaphore.h>

//DECLARAMOS LAS VARAIBLES(GLOBAL)
sem_t e;

int main(){

//INICIALIZAMOS EL SEMÁFORO(PRINCIPIO DEL MAIN)
sem_init(&e, 0, 5);
//WAIT(LOCK) ANTES DE LA SECCIÓN CRÍTICA
sem_wait(&e);
//SIGNAL(UNLOCK) DESPUES DE LA SECCIÓN CRÍTICIA
sem_post(&e);
//DESTROY AL FINAL
sem_destroy(&e);

}