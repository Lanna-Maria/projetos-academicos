#include <stdio.h>

int main() {
    int arr[5], valor, encontrado = 0;

    // Lê os 5 elementos do array
    printf("Digite 5 números:\n");
    for (int i = 0; i < 5; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Solicita ao usuário o valor a ser buscado
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &valor);

    // Busca o valor no array
    for (int i = 0; i < 5; i++) {
        if (arr[i] == valor) {
            printf("Valor encontrado na posição %d.\n", i + 1); // Posições começam em 1
            encontrado = 1;
            break;
        }
    }

    // Caso o valor não tenha sido encontrado
    if (!encontrado) {
        printf("Valor não encontrado no array.\n");
    }

    return 0;
}
