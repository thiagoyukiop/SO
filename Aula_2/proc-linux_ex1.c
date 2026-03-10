#include <stdio.h>
#include <unistd.h>

int main() {
    // Imprime o ID do processo primeiro (pai de todos)
    printf("Processo original: PID = %d\n", getpid());
    printf("------------------------------\n");

    pid_t f1 = fork(); // Cria um processo filho
    if (f1 == 0) {
        printf("Filho do Fork 1 criado! Meu PID = %d | Meu Pai (PPID): %d\n", getpid(), getppid()); // Imprime "hello" no processo filho
    }
    
    pid_t f2 = fork(); // Cria dois processos filhos (um para cada processo existente)
    if (f2 == 0) {
        printf("Filho do Fork 2 criado! Meu PID = %d | Meu Pai (PPID): %d\n", getpid(), getppid()); // Resultando em 4 prints de "hello"
    }
    
    pid_t f3 = fork(); // Cria quatro processos filhos (um para cada processo existente)
    if (f3 == 0) {
        printf("Filho do Fork 3 criado! Meu PID = %d | Meu Pai (PPID): %d\n", getpid(), getppid()); // Resultando em 8 prints de "hello"
    }
    sleep(1); // Adiciona um pequeno atraso para garantir que todos os processos imprimam antes de terminar
    return 0;
}