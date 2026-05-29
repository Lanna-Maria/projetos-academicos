#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct Endereco (opcional, pode remover se quiser algo mais simples)
struct Endereco {
    char rua[50];
    int numero;
};

// Struct Aluno com struct interna
struct Aluno {
    char nome[50];
    int matricula;
    float media;
    struct Endereco endereco;
};

// Função que aloca dinamicamente memória para um Aluno
struct Aluno* criaAluno() {
    return (struct Aluno*)malloc(sizeof(struct Aluno));
}

int main() {
    struct Aluno *aluno = criaAluno(); // alocação dinâmica

    if (aluno == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Preenchendo os dados
    printf("Digite o nome do aluno: ");
    fgets(aluno->nome, sizeof(aluno->nome), stdin);
    aluno->nome[strcspn(aluno->nome, "\n")] = '\0';

    printf("Digite a matrícula: ");
    scanf("%d", &aluno->matricula);

    printf("Digite a média: ");
    scanf("%f", &aluno->media);
    getchar(); // limpar o buffer

    printf("Digite a rua: ");
    fgets(aluno->endereco.rua, sizeof(aluno->endereco.rua), stdin);
    aluno->endereco.rua[strcspn(aluno->endereco.rua, "\n")] = '\0';

    printf("Digite o número da casa: ");
    scanf("%d", &aluno->endereco.numero);

    // Exibindo os dados
    printf("\nDados do Aluno:\n");
    printf("Nome: %s\n", aluno->nome);
    printf("Matrícula: %d\n", aluno->matricula);
    printf("Média: %.2f\n", aluno->media);
    printf("Endereço: Rua %s, nº %d\n", aluno->endereco.rua, aluno->endereco.numero);

    // Liberação da memória
    free(aluno);

    return 0;
}
