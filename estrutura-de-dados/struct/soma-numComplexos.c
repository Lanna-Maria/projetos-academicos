#include <stdio.h>

// Definição da struct Complexo
typedef struct {
    float parte_real;
    float parte_imaginaria;
} Complexo;

// Função que soma dois números complexos
Complexo soma_complexos(Complexo c1, Complexo c2) {
    Complexo resultado;
    resultado.parte_real = c1.parte_real + c2.parte_real;
    resultado.parte_imaginaria = c1.parte_imaginaria + c2.parte_imaginaria;
    return resultado;
}

int main() {
    Complexo num1, num2, soma;

    // Exemplo de entrada
    printf("Digite a parte real do primeiro número complexo: ");
    scanf("%f", &num1.parte_real);
    printf("Digite a parte imaginária do primeiro número complexo: ");
    scanf("%f", &num1.parte_imaginaria);

    printf("Digite a parte real do segundo número complexo: ");
    scanf("%f", &num2.parte_real);
    printf("Digite a parte imaginária do segundo número complexo: ");
    scanf("%f", &num2.parte_imaginaria);

    // Soma
    soma = soma_complexos(num1, num2);

    // Resultado
    printf("Resultado da soma: %.2f + %.2fi\n", soma.parte_real, soma.parte_imaginaria);

    return 0;
}
