#include <stdio.h>
#include <string.h>


// Definição da struct Aluno
struct Aluno {
    char nome[50];
    int matricula;
    float media;
};


// Função para imprimir os dados dos alunos
void imprimeAlunos(struct Aluno *alunos, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Matrícula: %d\n", alunos[i].matricula);
        printf("Média: %.2f\n", alunos[i].media);
    }
}


int main() {
    struct Aluno turma[3];

    // Coletando dados do teclado
    for (int i = 0; i < 3; i++) {
        printf("Digite os dados do aluno %d:\n", i + 1);

        printf("Nome: ");
        // Lê uma string com espaços
        fgets(turma[i].nome, sizeof(turma[i].nome), stdin);
        // Remove o \n do final (caso exista)
        turma[i].nome[strcspn(turma[i].nome, "\n")] = '\0';

        printf("Matrícula: ");
        scanf("%d", &turma[i].matricula);

        printf("Média: ");
        scanf("%f", &turma[i].media);

        // Limpar o buffer do teclado após scanf
        getchar();
    }


    // Exibe os dados
    imprimeAlunos(turma, 3);

    return 0;
}

