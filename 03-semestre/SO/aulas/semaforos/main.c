#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
// --- Configurações ---
#define NUM_THREADS 5 // Número de threads que vamos criar
#define INCREMENTS_PER_THREAD 100000 // Quantas vezes cada thread vai incrementar o contador
// --- Variáveis Globais Compartilhadas ---
volatile int shared_counter = 0; // O contador compartilhado. 'volatile' sugere ao compilador 
// que o valor pode mudar de formas inesperadas (ex: por outra thread)
pthread_mutex_t counter_mutex; // O mutex para proteger o contador
// --- Função que cada thread executará (sem proteção) ---
void* increment_counter_unsafe(void* arg) {
  long thread_id = (long)arg; // Apenas para identificar a thread, se necessário
  printf("Thread %ld iniciada (unsafe).\n", thread_id);
  for (int i = 0; i < INCREMENTS_PER_THREAD; i++) {
    // Operação NÃO SEGURA (race condition pode ocorrer aqui)
    // Isso pode ser decomposto em: Qual é a ideia? O Programa em C
    // 1. Ler shared_counter para um registrador
    // 2. Incrementar o valor no registrador
    // 3. Escrever o valor do registrador de volta para shared_counter
    // Outra thread pode interferir entre esses passos!
    shared_counter++;
    // printf("Thread %ld incrementou o contador para %d.\n", thread_id, shared_counter);
  }
  printf("Thread %ld finalizada (unsafe).\n", thread_id);
  return NULL;
}

// --- Função que cada thread executará (com proteção) ---
void* increment_counter_safe(void* arg) {
  long thread_id = (long)arg; // Apenas para identificar a thread, se necessário
  printf("Thread %ld iniciada (safe).\n", thread_id);
  for (int i = 0; i < INCREMENTS_PER_THREAD; i++) {
    // Operação SEGURA (race condition evitado)
    // Isso pode ser decomposto em: Qual é a ideia? O Programa em C
    // 1. Ler shared_counter para um registrador
    // 2. Incrementar o valor no registrador
    // 3. Escrever o valor do registrador de volta para shared_counter
    // Outra thread pode interferir entre esses passos!
    pthread_mutex_lock(&counter_mutex);
    shared_counter++;
    pthread_mutex_unlock(&counter_mutex);
    // printf("Thread %ld incrementou o contador para %d.\n", thread_id, shared_counter);
  }
  printf("Thread %ld finalizada (safe).\n", thread_id);
  return NULL;
}

pthread_t threads[NUM_THREADS];

int main () {
  int i;
  pthread_mutex_init(&counter_mutex, NULL);
  for (i = 0; i < NUM_THREADS; i++) {
    pthread_create(&threads[i], NULL, increment_counter_safe, (void*)i);
  }

  for (i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  printf("Contador final: %d\n", shared_counter);
  return 0;
}
