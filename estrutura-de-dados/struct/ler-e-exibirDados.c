#include <stdio.h>

// Definição da struct Endereco
struct Endereco {
    char rua[50];
    int numero;
    char cidade[50];
    char estado[3];  // 2 caracteres + '\0'
};

// Definição da struct Pessoa
struct Pessoa {
    char nome[50];
    int idade;
    struct Endereco endereco;
};

int main() {
    struct Pessoa p;

    // Leitura dos dados da pessoa
    printf("Digite o nome: ");
    fgets(p.nome, 50, stdin);
    // Remove '\n' do nome
    int len = 0;
    while (p.nome[len] != '\0') len++;
    if (len > 0 && p.nome[len - 1] == '\n') {
        p.nome[len - 1] = '\0';
    }

    printf("Digite a idade: ");
    scanf("%d", &p.idade);
    getchar();  // limpar buffer do teclado

    // Leitura do endereço
    printf("Digite a rua: ");
    fgets(p.endereco.rua, 50, stdin);
    // Remove '\n' da rua
    len = 0;
    while (p.endereco.rua[len] != '\0') len++;
    if (len > 0 && p.endereco.rua[len - 1] == '\n') {
        p.endereco.rua[len - 1] = '\0';
    }

    printf("Digite o número: ");
    scanf("%d", &p.endereco.numero);
    getchar(); // limpar buffer

    printf("Digite a cidade: ");
    fgets(p.endereco.cidade, 50, stdin);
    // Remove '\n' da cidade
    len = 0;
    while (p.endereco.cidade[len] != '\0') len++;
    if (len > 0 && p.endereco.cidade[len - 1] == '\n') {
        p.endereco.cidade[len - 1] = '\0';
    }

    printf("Digite o estado (sigla - 2 letras): ");
    fgets(p.endereco.estado, 3, stdin);
    getchar(); // limpar buffer

    // Exibição dos dados
    printf("\n--- Dados da Pessoa ---\n");
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Endereço:\n");
    printf("  Rua: %s, %d\n", p.endereco.rua, p.endereco.numero);
    printf("  Cidade: %s\n", p.endereco.cidade);
    printf("  Estado: %s\n", p.endereco.estado);

    return 0;
}


