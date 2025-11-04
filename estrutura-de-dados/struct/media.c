#include <stdio.h>

// Definição da struct Aluno
struct Aluno {
    char nome[50];
    int matricula;
    float nota1, nota2, nota3;
};

int main() {
    struct Aluno alunos[10];

    for (int i = 0; i < 10; i++) {
        printf("Cadastro do aluno %d\n", i + 1);

        printf("Nome: ");
        getchar(); // limpar buffer antes do fgets
        fgets(alunos[i].nome, 50, stdin);
        // remover '\n' do final
        int len = 0;
        while (alunos[i].nome[len] != '\0') len++;
        if (len > 0 && alunos[i].nome[len - 1] == '\n') {
            alunos[i].nome[len - 1] = '\0';
        }

        printf("Matrícula: ");
        scanf("%d", &alunos[i].matricula);

        printf("Nota 1: ");
        scanf("%f", &alunos[i].nota1);

        printf("Nota 2: ");
        scanf("%f", &alunos[i].nota2);

        printf("Nota 3: ");
        scanf("%f", &alunos[i].nota3);

        printf("\n");
    }

    printf("--- Resultado dos alunos ---\n");

    for (int i = 0; i < 10; i++) {
        float media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3.0;

        printf("Aluno: %s\n", alunos[i].nome);
        printf("Matrícula: %d\n", alunos[i].matricula);
        printf("Média: %.2f - ", media);

        if (media >= 7.0) {
            printf("Aprovado\n\n");
        } else {
            printf("Reprovado\n\n");
        }
    }

    return 0;
}

