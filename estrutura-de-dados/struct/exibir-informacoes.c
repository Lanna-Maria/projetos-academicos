#include <stdio.h>
#include <string.h>

// Definição da struct Livro
struct Livro {
    char titulo[100];
    char autor[50];
    int ano_publicacao;
};

int main() {
    struct Livro livros[5];

    // Cadastro dos livros
    for (int i = 0; i < 5; i++) {
        printf("Cadastro do Livro %d\n", i + 1);
        
        printf("Digite o título: ");
        getchar(); // Limpa o buffer antes de usar fgets
        fgets(livros[i].titulo, 100, stdin);
        livros[i].titulo[strcspn(livros[i].titulo, "\n")] = '\0'; // Remove o \n

        printf("Digite o autor: ");
        fgets(livros[i].autor, 50, stdin);
        livros[i].autor[strcspn(livros[i].autor, "\n")] = '\0'; // Remove o \n

        printf("Digite o ano de publicação: ");
        scanf("%d", &livros[i].ano_publicacao);
        printf("\n");
    }

    // Exibição dos livros
    printf("\n--- Lista de Livros Cadastrados ---\n");
    for (int i = 0; i < 5; i++) {
        printf("Livro %d:\n", i + 1);
        printf("Título: %s\n", livros[i].titulo);
        printf("Autor: %s\n", livros[i].autor);
        printf("Ano de Publicação: %d\n\n", livros[i].ano_publicacao);
    }

    return 0;
}

