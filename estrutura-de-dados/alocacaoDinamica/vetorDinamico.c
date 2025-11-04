#include <stdio.h>
#include <stdlib.h>
int main() {
    int *vetor;
    int n, i;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    vetor = (int *) malloc(n * sizeof(int));
    if (vetor == NULL) {
        printf("Erro de alocação de memória!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Digite o valor para vetor[%d]: ", i);
        scanf("%d", &vetor[i]);
    }
    printf("Valores no vetor:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    free(vetor);
    return 0;
}
