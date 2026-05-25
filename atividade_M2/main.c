// Desenvolver um simulador de tempo discreto (orientado a ticks de relógio) que integre um escalonador de CPU Round Robin e um gerenciador
// de memória virtual com paginação sob demanda, utilizando o algoritmo de substituição de páginas LRU (Least Recently Used).
#include <stdio.h>  
#include <stdlib.h>  

#include <iostream>
#include <vector>
#include <iostream>
#include <ctime>
using namespace std;

#define quantum_rr 2;
#define ram 2;

struct Processo {
    int id;
    int paginas[MAX_PAGINAS];
    int total_paginas;
    int pagina_atual;

    int quantum_restante;
    int tique_desbloqueio;
    int estado;

    int total_page_faults;
    int tique chegada;
    int tique_conclusao;
};

struct Quadro {
    
}

int desbloquear_processos(int tique) {

}

int main() {
    int tique = 0, processos_fila_prontos = 0, processos_bloqueados = 0;

    while(processos_fila_prontos > 0 || processos_bloqueados > 0) {
        tique++;
        desbloquear_processos(tique);
    }

    return 0;
}