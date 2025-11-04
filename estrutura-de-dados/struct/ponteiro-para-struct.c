#include <stdio.h>
#include <string.h>

// Definindo a struct Aluno
struct Aluno {
    char nome[50];
    int matricula;
    float media;
};


int main() {
    // Declarando uma variável do tipo Aluno
    struct Aluno aluno1;

    // Declarando um ponteiro para Aluno e apontando para aluno1
    struct Aluno *ptrAluno = &aluno1;


    // Preenchendo os campos usando o ponteiro
    strcpy(ptrAluno->nome, "Lanna Maria"); //Usei a função strcpy que em C é usada para copiar uma string (texto) de uma variável para outra.
    ptrAluno->matricula = 789123;
    ptrAluno->media = 9.2;


    // Exibindo os dados usando o ponteiro
    printf("Dados do Aluno:\n");
    printf("Nome: %s\n", ptrAluno->nome);
    printf("Matrícula: %d\n", ptrAluno->matricula);
    printf("Média: %.2f\n", ptrAluno->media);

    return 0;
}

