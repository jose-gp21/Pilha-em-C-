#include <iostream> // Inclui a biblioteca para entrada e saída padrão (cin e cout)
using namespace std;

// Declaração das funções
int insere();       // Função para inserir um elemento na pilha
int remover();      // Função para remover um elemento específico da pilha
int mostrar();      // Função para mostrar todos os elementos da pilha
int consultar();    // Função para consultar o topo da pilha

// Declaração de variáveis globais
int topo = -1;      // Índice do topo da pilha (inicialmente -1, indicando que a pilha está vazia)
int pilha[5];       // Array que representa a pilha com um tamanho de 5
int elemento;       // Variável para armazenar o elemento a ser inserido/removido
int opcao = 1;      // Variável para armazenar a escolha do usuário no menu
int ind = 0;        // Variável auxiliar para iteração
int tam = 4;        // Tamanho máximo da pilha (0 a 4, total 5 elementos)

int main() {
    // Loop principal que mantém o menu até que o usuário escolha sair
    while ((opcao > 0) && (opcao < 6)) {
        // Exibe o menu de opções para o usuário
        cout << "\n---------------------------";
        cout << "\n     Algoritmo de Pilha    ";
        cout << "\n---------------------------";
        cout << "\n      1 = INSERIR          ";
        cout << "\n      2 = RETIRAR          ";
        cout << "\n      3 = MOSTRAR          ";
        cout << "\n      4 = CONSULTAR        ";
        cout << "\n      5 = SAIR             ";
        cout << "\n      ESCOLHA UMA OPCAO..: ";
        cin >> opcao;  // Lê a opção escolhida pelo usuário

        // Switch para tratar cada opção do menu
        switch (opcao) {
        case 1:
            insere();  // Chama a função para inserir um elemento na pilha
            break;

        case 2:
            remover(); // Chama a função para remover um elemento da pilha
            break;

        case 3:
            mostrar(); // Chama a função para mostrar os elementos da pilha
            break;

        case 4:
            consultar(); // Chama a função para consultar o topo da pilha
            break;

        case 5:
            opcao = 10;  // Define o valor de opcao para sair do loop
            break;

        default:
            cout << "\n\n\nOpcao Invalida" << endl; // Caso o usuário escolha uma opção inválida
            break;
        }
    }

    return 0;  // Retorna 0 para indicar que o programa terminou corretamente
}

// Função para inserir um elemento na pilha
int insere() {
    if (topo < tam) {  // Verifica se ainda há espaço na pilha
        topo++;  // Incrementa o topo para a nova posição
        cout << "\nTopo esta em.: " << topo;
        cout << "\nInforme Elemento p/Inserir.: ";
        cin >> pilha[topo];  // Lê o novo elemento e o coloca no topo da pilha
    } else {
        cout << "\nPilha esta cheia --------->>> Topo = " << topo; // A pilha está cheia
    }
    return 0;
}

// Função para remover um elemento específico da pilha
int remover() {
    int topo1 = -1;       // Topo auxiliar para uma segunda pilha temporária
    int pilha1[5];        // Pilha temporária usada para segurar elementos enquanto removemos

    if (topo >= 0) {      // Verifica se a pilha não está vazia
        cout << "\nElemento a ser retirado..: ";
        cin >> elemento;  // Lê o elemento que o usuário quer remover

        // Procura o elemento na pilha
        while (pilha[topo] != elemento) {
            topo1++;                  // Move para o topo da pilha temporária
            pilha1[topo1] = pilha[topo];  // Copia o elemento atual para a pilha temporária
            topo--;                   // Decrementa o topo da pilha original
            if (topo == -1) {         // Se chegou ao final da pilha e o elemento não foi encontrado
                cout << "\n\nNao existe o elemento solicitado";
                topo++;  // Reverte o decremento do topo para manter a pilha
                return 0;
            }
        }

        topo--;  // Remove o elemento encontrado da pilha original

        // Recoloca os elementos da pilha temporária de volta na original
        for (; topo1 >= 0; topo1--) {
            topo++;
            pilha[topo] = pilha1[topo1];
        }
    } else {
        cout << "\nPilha esta Vazia ------->>> Topo = " << topo; // A pilha está vazia
    }
    return 0;
}

// Função para mostrar todos os elementos da pilha
int mostrar() {
    if (topo == -1) {  // Verifica se a pilha está vazia
        cout << "\nPilha esta Vazia ------->>> Topo = " << topo;
    } else {
        // Itera sobre a pilha e imprime cada elemento
        for (ind = topo; ind >= 0; ind--) {
            cout << "\nPosicao.: " << ind << ". Conteudo.: " << pilha[ind];
        }
    }
    cout << endl;
    return 0;
}

// Função para consultar o topo da pilha
int consultar() {
    if (topo == -1) {  // Verifica se a pilha está vazia
        cout << "\nPilha esta Vazia ------->>> Topo = " << topo;
    } else {
        // Exibe o elemento no topo da pilha
        cout << "\nPosicao.: " << topo << ". Conteudo.: " << pilha[topo];
    }
    return 0;
}
