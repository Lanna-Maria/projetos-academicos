#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura de um nó da pilha
typedef struct No {
    int valor;             // Valor armazenado no nó
    struct No* proximo;    // Ponteiro para o próximo nó
} No;

// Função para empilhar (push)
void push(No** topo, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocação de memória.\n");
        return;
    }
    novo->valor = valor;
    novo->proximo = *topo;
    *topo = novo;
    printf("Valor %d empilhado.\n", valor);
}

// Função para desempilhar (pop)
int pop(No** topo) {
    if (*topo == NULL) {
        printf("Pilha vazia. Nada para desempilhar.\n");
        return -1; // Valor de erro
    }

    No* temp = *topo;
    int valor = temp->valor;
    *topo = temp->proximo;
    free(temp);
    printf("Valor %d desempilhado.\n", valor);
    return valor;
}

// Função para exibir os elementos da pilha
void exibir(No* topo) {
    if (topo == NULL) {
        printf("Pilha está vazia.\n");
        return;
    }

    printf("Elementos da pilha: ");
    while (topo != NULL) {
        printf("%d ", topo->valor);
        topo = topo->proximo;
    }
    printf("\n");
}

// Função para mostrar o topo da pilha sem remover
void verTopo(No* topo) {
    if (topo == NULL) {
        printf("A pilha está vazia.\n");
    } else {
        printf("Topo da pilha: %d\n", topo->valor);
    }
}

// Função para verificar se a pilha está vazia
int estaVazia(No* topo) {
    return topo == NULL;
}

// Função para liberar toda a memória da pilha
void liberarPilha(No** topo) {
    while (!estaVazia(*topo)) {
        pop(topo);
    }
}

// Função principal com menu interativo
int main() {
    No* pilha = NULL;
    int opcao, valor;

    do {
        printf("\n--- Menu da Pilha ---\n");
        printf("1 - Empilhar número\n");
        printf("2 - Desempilhar número\n");
        printf("3 - Exibir pilha\n");
        printf("4 - Ver topo da pilha\n");
        printf("5 - Verificar se pilha está vazia\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o número a empilhar: ");
                scanf("%d", &valor);
                push(&pilha, valor);
                break;
            case 2:
                pop(&pilha);
                break;
            case 3:
                exibir(pilha);
                break;
            case 4:
                verTopo(pilha);
                break;
            case 5:
                if (estaVazia(pilha)) {
                    printf("A pilha está vazia.\n");
                } else {
                    printf("A pilha NÃO está vazia.\n");
                }
                break;
            case 0:
                liberarPilha(&pilha);
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}

