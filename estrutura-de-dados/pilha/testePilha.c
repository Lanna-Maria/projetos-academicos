#include <stdio.h>
#include <stdlib.h>

#define MAX 50  // Capacidade máxima da pilha

typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

// Funções
void inicializar(Pilha *p) {
    p->topo = -1;
}

int isEmpty(Pilha *p) {
    return p->topo == -1;
}

int isFull(Pilha *p) {
    return p->topo == MAX - 1;
}

void push(Pilha *p, int valor) {
    if (isFull(p)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->itens[++p->topo] = valor;
    printf("Elemento %d inserido com sucesso.\n", valor);
}

int pop(Pilha *p) {
    if (isEmpty(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return p->itens[p->topo--];
}

int top(Pilha *p) {
    if (isEmpty(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return p->itens[p->topo];
}

void exibirPilha(Pilha *p) {
    if (isEmpty(p)) {
        printf("A pilha está vazia.\n");
        return;
    }
    printf("Pilha (topo -> base): ");
    for (int i = p->topo; i >= 0; i--) {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}

// Programa com menu interativo
int main() {
    Pilha p;
    inicializar(&p);
    int opcao, valor;

    do {
        printf("\n===== MENU PILHA =====\n");
        printf("1 - Inserir número na pilha\n");
        printf("2 - Remover número da pilha\n");
        printf("3 - Ver topo da pilha\n");
        printf("4 - Verificar se pilha está vazia\n");
        printf("5 - Verificar se pilha está cheia\n");
        printf("6 - Exibir todos os elementos da pilha\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um número para inserir: ");
                scanf("%d", &valor);
                push(&p, valor);
                break;
            case 2:
                valor = pop(&p);
                if (valor != -1)
                    printf("Elemento removido: %d\n", valor);
                break;
            case 3:
                valor = top(&p);
                if (valor != -1)
                    printf("Elemento no topo: %d\n", valor);
                break;
            case 4:
                printf(isEmpty(&p) ? "A pilha está vazia.\n" : "A pilha NÃO está vazia.\n");
                break;
            case 5:
                printf(isFull(&p) ? "A pilha está cheia.\n" : "A pilha NÃO está cheia.\n");
                break;
            case 6:
                exibirPilha(&p);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

