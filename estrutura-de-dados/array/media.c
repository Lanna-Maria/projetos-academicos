#include <stdio.h>

int main() {
    int numeros[5], soma = 0;
    float media;

    printf("Digite 5 números inteiros:\n");
    for(int i = 0; i < 5; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
        soma += numeros[i]; // Soma os valores
    }

    // Calcula a média
    media = (float)soma / 5;

    printf("Média dos números: %.2f\n", media);

    return 0;
}
