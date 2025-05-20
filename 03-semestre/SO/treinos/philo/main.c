#include <stdio.h>

#include <pthread.h>
#include <semaphore.h>

#define num_threads 5

pthread_t filosofos[num_threads];
sem_t garfos[num_threads];
sem_t lugares;

void * Filosofo(void * param){
  int aux = (int)param;
  // printf("Filosofo %d pensando\n", aux);
  sem_wait(&lugares);
  sem_wait(&garfos[aux]);
  sem_wait(&garfos[(aux+1) %5]);
  printf("Filosofo %d comendo\n", aux);
  sem_post(&garfos[aux]);
  sem_post(&garfos[(aux+1) %5]);
  sem_post(&lugares);
}

int main(){
  int j;
  sem_init(&lugares, 0, 4);
  for(j = 0; j<num_threads; j++){
    sem_init(&garfos[j], 0, 1);
  }

  for(j = 0; j< num_threads; j++){
    pthread_create(&filosofos[j], NULL, Filosofo, (void*)j);
  }

  for(j = 0; j< num_threads; j++){
    pthread_join(filosofos[j], NULL);
  }

  printf("Filosofos finalizados\n");
  return 0;
}
