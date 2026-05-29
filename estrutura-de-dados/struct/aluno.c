#include <stdio.h>
#include <string.h>

// Definição da struct Aluno
struct Aluno {
    char nome[50];
    int matricula;
    float media;
};

int main() {
    // Declaração de uma variável do tipo Aluno
    struct Aluno aluno1;
    // Preenchendo os campos com dados fictícios
    strcpy(aluno1.nome, "Lanna Maria"); //Usei a função strcpy que em C é usada para copiar uma string (texto) de uma variável para outra.
    aluno1.matricula = 123456;
    aluno1.media = 8.7;

    // Exibindo os dados na tela
    printf("Dados do Aluno:\n");
    printf("Nome: %s\n", aluno1.nome);
    printf("Matrícula: %d\n", aluno1.matricula);
    printf("Média: %.2f\n", aluno1.media);
    return 0;
}
