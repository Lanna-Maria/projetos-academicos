#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 50

int main() {
    int n, i;
    char **palavras;

    printf("Quantas palavras você quer digitar? ");
    scanf("%d", &n);

    // Aloca espaço para os ponteiros de palavras
    palavras = (char **) malloc(n * sizeof(char *));
    if (palavras == NULL) {
        printf("Erro ao alocar memória para os ponteiros!\n");
        return 1;
    }
    // Limpar o buffer do teclado (importante após scanf com %d)
    getchar();
    for (i = 0; i < n; i++) {
        palavras[i] = (char *) malloc(TAM_MAX * sizeof(char));
        if (palavras[i] == NULL) {
            printf("Erro ao alocar memória para a palavra %d\n", i);
            return 1;
        }
        printf("Digite a palavra %d: ", i + 1);
        fgets(palavras[i], TAM_MAX, stdin);
        // Remove o '\n' deixado pelo fgets
        palavras[i][strcspn(palavras[i], "\n")] = '\0';
    }
    // Exibe as palavras em ordem inversa
    printf("\nPalavras em ordem inversa:\n");
    for (i = n - 1; i >= 0; i--) {
        printf("%s\n", palavras[i]);
    }
    for (i = 0; i < n; i++) {
        free(palavras[i]); // Liberando a memória alocada para cada palavra.
    }
    free(palavras); // Liberando a memória alocada para o vetor de ponteiros.
    return 0;
}

