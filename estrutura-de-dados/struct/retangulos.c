#include <stdio.h>

// Definição da struct Retangulo
typedef struct {
    float base;
    float altura;
} Retangulo;

// Função para calcular área
float calcular_area(Retangulo r) {
    return r.base * r.altura;
}

// Função para calcular perímetro
float calcular_perimetro(Retangulo r) {
    return 2 * (r.base + r.altura);
}

int main() {
    Retangulo ret;

    printf("Digite a base do retângulo: ");
    scanf("%f", &ret.base);

    printf("Digite a altura do retângulo: ");
    scanf("%f", &ret.altura);

    float area = calcular_area(ret);
    float perimetro = calcular_perimetro(ret);

    printf("Área: %.2f\n", area);
    printf("Perímetro: %.2f\n", perimetro);

    return 0;
}

