// Soma de valores inteiros usando alocação dinâmica
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *valores;
    int quantidade, i, soma = 0;

    // Solicita a quantidade de números
    printf("Quantos números você deseja somar? ");
    scanf("%d", &quantidade);

    // Aloca memória para os inteiros
    valores = (int *) malloc(quantidade * sizeof(int));

    // Verifica se a alocação foi bem-sucedida
    if (valores == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Lê os valores e acumula a soma
    for (i = 0; i < quantidade; i++) {
        printf("Digite o número %d: ", i + 1);
        scanf("%d", &valores[i]);
        soma += valores[i];
    }

    // Mostra o resultado
    printf("A soma dos valores é: %d\n", soma);

    // Libera a memória alocada
    free(valores);

    return 0;
}


