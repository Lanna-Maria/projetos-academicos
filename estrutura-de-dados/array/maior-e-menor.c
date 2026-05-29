#include <stdio.h>

int main() {
    int numeros[5], maior, menor;

    printf("Digite 5 números:\n");
    for(int i = 0; i < 5; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Inicializa maior e menor com o primeiro elemento do array
    maior = menor = numeros[0];

    // Encontra o maior e o menor número
    for(int i = 1; i < 5; i++) {
        if(numeros[i] > maior) {
            maior = numeros[i];
        }
        if(numeros[i] < menor) {
            menor = numeros[i];
        }
    }

    printf("Maior número: %d\n", maior);
    printf("Menor número: %d\n", menor);

    return 0;
}
rn 0;
}
