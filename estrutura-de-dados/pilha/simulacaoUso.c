#include <stdio.h>
#define MAX 5

int pilha[MAX];
int topo = -1;

void push(int valor) {
    if (topo == MAX - 1) {
        printf("Erro: pilha cheia, nao é possível inserir %d\n", valor);
    } else {
        pilha[++topo] = valor;
        printf("push(%d) -> ", valor);
        imprimePilha();
    }
}

void pop() {
    if (topo == -1) {
        printf("Erro: pilha vazia\n");
    } else {
        printf("pop() -> removeu %d\n", pilha[topo--]);
        imprimePilha();
    }
}

void top() {
    if (topo == -1) {
        printf("Pilha vazia\n");
    } else {
        printf("top() -> %d\n", pilha[topo]);
    }
}

void imprimePilha() {
    printf("Pilha: ");
    for (int i = 0; i <= topo; i++) {
        printf("%d ", pilha[i]);
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    pop();
    top();
    push(40);
    push(50);
    push(60);
    push(70); // Deve indicar que a pilha está cheia

    printf("\nEstado final da pilha (do topo para a base):\n");
    for (int i = topo; i >= 0; i--) {
        printf("%d ", pilha[i]);
    }
    printf("\n");

    return 0;
}
