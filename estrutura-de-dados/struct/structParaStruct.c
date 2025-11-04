#include <stdio.h>
#include <string.h>

// Struct Endereco
struct Endereco {
    char rua[50];
    int numero;
};

// Struct Aluno com Endereco interno
struct Aluno {
    char nome[50];
    int matricula;
    float media;
    struct Endereco endereco;
};

int main() {
    struct Aluno aluno;
    // Coleta dos dados do aluno
    printf("Digite o nome do aluno: ");
    fgets(aluno.nome, sizeof(aluno.nome), stdin); //A função  fgets é usada para ler uma linha de texto, incluindo espaços, de forma segura, sendo muito útil para capturar strings que contêm nomes completos, endereços, frases, etc.

    aluno.nome[strcspn(aluno.nome, "\n")] = '\0'; // remove o \n

    printf("Digite a matrícula: ");
    scanf("%d", &aluno.matricula);
    printf("Digite a média: ");
    scanf("%f", &aluno.media);
    getchar(); // limpar o buffer do scanf

    // Coleta dos dados do endereço
    printf("Digite a rua: ");
    fgets(aluno.endereco.rua, sizeof(aluno.endereco.rua), stdin);     aluno.endereco.rua[strcspn(aluno.endereco.rua, "\n")] = '\0';
    printf("Digite o número da casa: ");
    scanf("%d", &aluno.endereco.numero);

    // Exibição dos dados
    printf("\nDados do Aluno:\n");
    printf("Nome: %s\n", aluno.nome);
    printf("Matrícula: %d\n", aluno.matricula);
    printf("Média: %.2f\n", aluno.media);
    printf("Endereço: Rua %s, nº %d\n", aluno.endereco.rua, aluno.endereco.numero);
    return 0;
}
