#include <stdio.h>
#include <stdlib.h>

// Função que recebe dois ponteiros para inteiros e retorna a soma dos valores
int soma(int *a, int *b) {
    return *a + *b;
}

int main() {
    int x, y, resultado;

    // Leitura dos dois números inteiros
    printf("Digite o primeiro número: ");
    scanf("%d", &x);

    printf("Digite o segundo número: ");
    scanf("%d", &y);

    // Chamada da função soma
    resultado = soma(&x, &y);

    // Exibe o resultado
    printf("A soma de %d e %d é: %d\n", x, y, resultado);

    return 0;
}


