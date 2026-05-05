// Exercício Prático: Simulador de Page Fault em C++
#include <stdio.h>  
#include <stdlib.h>  

#include <iostream>
#include <vector>
#include <iostream>
#include <ctime>
using namespace std;

// ESTRUTURA DE DADOS
#define TAM 10

struct pagina_processo {
    int numero_frame;
    char bit_validade;
};

int main() {
    std::vector<pagina_processo> tabela_paginas;
    srand(time(NULL));

    // INICIALIZAÇÃO 

    cout << "Primeira tabela" << endl;

    for(int i = 0; i < TAM; i++) {
        pagina_processo p_aux = {-1, 'i'};
        tabela_paginas.push_back(p_aux);
    }

    for(const auto& pag : tabela_paginas) {
        cout << "numero_frame: " << pag.numero_frame << "| bit_validade: " << pag.bit_validade << endl;
    }

    int aux;
    for(int i = 0; i < TAM/2; i++) {
        aux = rand() % TAM;
        bool memoria_ocupada = false;
        for(const auto& pag : tabela_paginas) {
            if(aux == pag.numero_frame) {
                cout << "Esse posicao da RAM (" << aux << ") ja esta preenchida";
                memoria_ocupada = true;
                break;
            }
        }

        if(!memoria_ocupada) {
            tabela_paginas[i].numero_frame = aux;
            tabela_paginas[i].bit_validade = 'v';
        }
        else {
            i--;
            continue;
        }
    }

    cout << "Segunda tabela" << endl;

    for(const auto& pag : tabela_paginas) {
        cout << "numero_frame: " << pag.numero_frame << "| bit_validade: " << pag.bit_validade << endl;
    }

    // SIMULAÇÃO DE ACESSOS

    std::vector<int> sequencia_acessos = {3, 8, 1};

    for(const auto& num : sequencia_acessos) {
        cout << endl << "Sequencia de Acessos: " << num << endl << endl;
        if(tabela_paginas[num].bit_validade == 'v') {
            cout << "O acesso foi rapido e direto na RAM, frame: " << tabela_paginas[num].numero_frame << endl;
        }
        else if(tabela_paginas[num].bit_validade == 'i') {
            cout << "PAGE FAULT: Pagina "<< num << " nao esta na RAM." << endl;
            bool memoria_cheia = true;
            for(int i = 0; i < TAM; i++) {
                if(tabela_paginas[i].bit_validade == 'i') {
                    cout << "Primeiro frame livro na RAM: " << i << endl;
                    tabela_paginas[i].numero_frame = num;
                    tabela_paginas[i].bit_validade = 'v';
                    cout << "Resolvido: Pagina "<< num << " carregada do disco para o frame " << i;
                    cout << ". Instrucao reinicializada." << endl;
                    memoria_cheia = false;
                    break;
                }
            }
            if (memoria_cheia) {
                cout << "OUT OF MEMORY";
            }
        }
    }

    cout << "Terceira tabela" << endl;

    for(const auto& pag : tabela_paginas) {
        cout << "numero_frame: " << pag.numero_frame << "| bit_validade: " << pag.bit_validade << endl;
    }

    return 0;
}