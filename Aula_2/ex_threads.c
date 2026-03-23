#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 10

void *tarefa_da_thread(void* arg) {
    int id = *(int*)arg;
    printf("Thread %d em execução...\n", id);
    free(arg);
    pthread_exit(NULL);
}

int main() {
    pthread_t workers[NUM_THREADS];
    
    for(int i = 0; i < NUM_THREADS; i++) {
        int* id = malloc(sizeof(int));
        *id = i;
        pthread_create(&workers[i], NULL, tarefa_da_thread, id);
    }
    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(workers[i], NULL);
        printf("Thread %d finalizada e unida ao processo principal.\n", i);
    }
    printf("Todas as threads terminaram. Encerrando o programa.\n");
    return 0;
}
