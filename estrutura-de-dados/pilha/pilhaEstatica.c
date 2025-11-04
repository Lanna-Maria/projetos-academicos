#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Capacidade da pilha

// Estrutura da pilha
typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

// Inicializa a pilha
void inicializar(Pilha *p) {
    p->topo = -1;  // Pilha vazia
}

// Verifica se a pilha está vazia
int isEmpty(Pilha *p) {
    return p->topo == -1;
}

// Verifica se a pilha está cheia
int isFull(Pilha *p) {
    return p->topo == MAX - 1;
}

// Adiciona elemento no topo (push)
void push(Pilha *p, int valor) {
    if (isFull(p)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->itens[++p->topo] = valor;
    printf("Elemento %d inserido com sucesso.\n", valor);
}

// Remove elemento do topo (pop)
int pop(Pilha *p) {
    if (isEmpty(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1;  // Retorno para indicar erro
    }
    return p->itens[p->topo--];
}

// Consulta o elemento no topo (top)
int top(Pilha *p) {
    if (isEmpty(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return p->itens[p->topo];
}

// Programa de teste
int main() {
    Pilha p;
    inicializar(&p);

    push(&p, 10);
    push(&p, 20);
    push(&p, 30);
    push(&p, 40);
    push(&p, 50);
    push(&p, 60); // Teste de pilha cheia

    printf("Topo da pilha: %d\n", top(&p));

    printf("Elemento removido: %d\n", pop(&p));
    printf("Elemento removido: %d\n", pop(&p));

    printf("Topo da pilha agora: %d\n", top(&p));

    return 0;
}
