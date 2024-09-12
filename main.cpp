#include <iostream> // Inclui a biblioteca para entrada e sa�da padr�o (cin e cout)
using namespace std;

// Declara��o das fun��es
int insere();       // Fun��o para inserir um elemento na pilha
int remover();      // Fun��o para remover um elemento espec�fico da pilha
int mostrar();      // Fun��o para mostrar todos os elementos da pilha
int consultar();    // Fun��o para consultar o topo da pilha

// Declara��o de vari�veis globais
int topo = -1;      // �ndice do topo da pilha (inicialmente -1, indicando que a pilha est� vazia)
int pilha[5];       // Array que representa a pilha com um tamanho de 5
int elemento;       // Vari�vel para armazenar o elemento a ser inserido/removido
int opcao = 1;      // Vari�vel para armazenar a escolha do usu�rio no menu
int ind = 0;        // Vari�vel auxiliar para itera��o
int tam = 4;        // Tamanho m�ximo da pilha (0 a 4, total 5 elementos)

int main() {
    // Loop principal que mant�m o menu at� que o usu�rio escolha sair
    while ((opcao > 0) && (opcao < 6)) {
        // Exibe o menu de op��es para o usu�rio
        cout << "\n---------------------------";
        cout << "\n     Algoritmo de Pilha    ";
        cout << "\n---------------------------";
        cout << "\n      1 = INSERIR          ";
        cout << "\n      2 = RETIRAR          ";
        cout << "\n      3 = MOSTRAR          ";
        cout << "\n      4 = CONSULTAR        ";
        cout << "\n      5 = SAIR             ";
        cout << "\n      ESCOLHA UMA OPCAO..: ";
        cin >> opcao;  // L� a op��o escolhida pelo usu�rio

        // Switch para tratar cada op��o do menu
        switch (opcao) {
        case 1:
            insere();  // Chama a fun��o para inserir um elemento na pilha
            break;

        case 2:
            remover(); // Chama a fun��o para remover um elemento da pilha
            break;

        case 3:
            mostrar(); // Chama a fun��o para mostrar os elementos da pilha
            break;

        case 4:
            consultar(); // Chama a fun��o para consultar o topo da pilha
            break;

        case 5:
            opcao = 10;  // Define o valor de opcao para sair do loop
            break;

        default:
            cout << "\n\n\nOpcao Invalida" << endl; // Caso o usu�rio escolha uma op��o inv�lida
            break;
        }
    }

    return 0;  // Retorna 0 para indicar que o programa terminou corretamente
}

// Fun��o para inserir um elemento na pilha
int insere() {
    if (topo < tam) {  // Verifica se ainda h� espa�o na pilha
        topo++;  // Incrementa o topo para a nova posi��o
        cout << "\nTopo esta em.: " << topo;
        cout << "\nInforme Elemento p/Inserir.: ";
        cin >> pilha[topo];  // L� o novo elemento e o coloca no topo da pilha
    } else {
        cout << "\nPilha esta cheia --------->>> Topo = " << topo; // A pilha est� cheia
    }
    return 0;
}

// Fun��o para remover um elemento espec�fico da pilha
int remover() {
    int topo1 = -1;       // Topo auxiliar para uma segunda pilha tempor�ria
    int pilha1[5];        // Pilha tempor�ria usada para segurar elementos enquanto removemos

    if (topo >= 0) {      // Verifica se a pilha n�o est� vazia
        cout << "\nElemento a ser retirado..: ";
        cin >> elemento;  // L� o elemento que o usu�rio quer remover

        // Procura o elemento na pilha
        while (pilha[topo] != elemento) {
            topo1++;                  // Move para o topo da pilha tempor�ria
            pilha1[topo1] = pilha[topo];  // Copia o elemento atual para a pilha tempor�ria
            topo--;                   // Decrementa o topo da pilha original
            if (topo == -1) {         // Se chegou ao final da pilha e o elemento n�o foi encontrado
                cout << "\n\nNao existe o elemento solicitado";
                topo++;  // Reverte o decremento do topo para manter a pilha
                return 0;
            }
        }

        topo--;  // Remove o elemento encontrado da pilha original

        // Recoloca os elementos da pilha tempor�ria de volta na original
        for (; topo1 >= 0; topo1--) {
            topo++;
            pilha[topo] = pilha1[topo1];
        }
    } else {
        cout << "\nPilha esta Vazia ------->>> Topo = " << topo; // A pilha est� vazia
    }
    return 0;
}

// Fun��o para mostrar todos os elementos da pilha
int mostrar() {
    if (topo == -1) {  // Verifica se a pilha est� vazia
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

// Fun��o para consultar o topo da pilha
int consultar() {
    if (topo == -1) {  // Verifica se a pilha est� vazia
        cout << "\nPilha esta Vazia ------->>> Topo = " << topo;
    } else {
        // Exibe o elemento no topo da pilha
        cout << "\nPosicao.: " << topo << ". Conteudo.: " << pilha[topo];
    }
    return 0;
}
