#include <stdio.h>

int main() {
    int numeros[10];
    int i;

    printf("Digite 10 números inteiros:\n");
    for(i = 0; i < 10; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    printf("\nNúmeros pares digitados:\n");
    for(i = 0; i < 10; i++) {
        if(numeros[i] % 2 == 0) {
            printf("%d ", numeros[i]);
        }
    }

    printf("\n");
    return 0;
}
