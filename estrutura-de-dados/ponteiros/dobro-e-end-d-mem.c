#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeros[5];
    int *ponteiro;
    int i;

    printf("Digite 5 números inteiros:\n");
    for(i = 0; i < 5; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Ponteiro aponta para o início do array
    ponteiro = numeros;

    printf("\nDobro de cada número e seus endereços de memória:\n");
    for(i = 0; i < 5; i++) {
        printf("Número: %d, Dobro: %d, Endereço: %p\n", *(ponteiro + i), *(ponteiro + i) * 2, (ponteiro + i));
    }

    return 0;
}

