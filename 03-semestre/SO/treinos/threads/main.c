#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Lib para gerenciamento de threads
#include <pthread.h>
#include <semaphore.h>

// Lib para controle de tempo de execução
#include <unistd.h>

#define num_threads 2

pthread_t threads[num_threads];
pthread_mutex_t lock;
sem_t semaphore;

void * thread_function_1(void * param);
void * thread_function_2(void * param);

int main() {
	int parametro = 0;
	int *param = &parametro;

	sem_init(&semaphore, 0, 1);

	if(pthread_create(&threads[0], NULL, thread_function_1, (void *)param) != 0){
		perror("Erro ao criar a thread 1");
		return 1;
	}

	if(pthread_create(&threads[1], NULL, thread_function_2, (void *)param) != 0){
		perror("Erro ao criar a thread 2");
		return 1;
	}

	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);

	printf("Threads finalizadas com sucesso!\n");
	return 0; 
}


void * thread_function_1(void * param){
	int *aux = (int *)param;

	for(int i = 1; i<=10; i++){
		//pthread_mutex_lock(&lock);
		sem_wait(&semaphore);
		*aux = *aux +1;

		printf("Linha %d: thread 1 - i %d - valor do parametro %d\n", i, i, *aux);

		if(i==10){
			printf("\nThread 1 finalizada na função\n\n");
		}
		//pthread_mutex_unlock(&lock);
		sem_post(&semaphore);
	}
	pthread_exit(NULL);
}

void * thread_function_2(void * param){
	int *aux = (int *)param;

	for(int i = 1; i<=10; i++){
		//pthread_mutex_lock(&lock);
		sem_wait(&semaphore);
		*aux = *aux +1;

		printf("Linha %d: thread 2 - i %d - valor do parametro %d\n", i, i, *aux);

		if(i==10){
			printf("\nThread 2 finalizada na função\n\n");
		}
		//pthread_mutex_unlock(&lock);
		sem_post(&semaphore);
	}
	pthread_exit(NULL);
}

