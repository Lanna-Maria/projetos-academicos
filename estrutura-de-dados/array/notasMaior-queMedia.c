#include <stdio.h>

int main() {
    int notas[5] = {7, 8, 6, 5, 9};
    int i;
    float soma = 0, media;

    for(i = 0; i < 5; i++) {
        soma += notas[i];
    }

    media = soma / 5;

    printf("Média das notas: %.2f\n", media);

    printf("Notas maiores que a média:\n");
    for(i = 0; i < 5; i++) {
        if(notas[i] > media) {
            printf("%d ", notas[i]);
        }
    }

    printf("\n");
    return 0;
}
