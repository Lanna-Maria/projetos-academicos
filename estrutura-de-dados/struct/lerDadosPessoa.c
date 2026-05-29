#include <stdio.h>

// Definição da struct Pessoa
struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};

int main() {
    struct Pessoa p;

    // Leitura dos dados
    printf("Digite o nome: ");
    fgets(p.nome, 50, stdin);  // lê o nome com espaços
    printf("Digite a idade: ");
    scanf("%d", &p.idade);
    printf("Digite a altura (em metros): ");
    scanf("%f", &p.altura);

    // Impressão dos dados
    printf("\n--- Dados da Pessoa ---\n");
    printf("Nome: %s", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Altura: %.2f metros\n", p.altura);

    return 0;
}
