#include <stdio.h>

// Definição da struct Produto
struct Produto {
    int codigo;
    char nome[30];
    float preco;
};

int main() {
    struct Produto produtos[3];
    float soma_precos = 0;

    // Cadastro dos produtos
    for (int i = 0; i < 3; i++) {
        printf("Cadastro do Produto %d\n", i + 1);

        printf("Código: ");
        scanf("%d", &produtos[i].codigo);

        printf("Nome: ");
        getchar(); // Limpar buffer antes de fgets
        fgets(produtos[i].nome, 30, stdin);
        // Remove \n do final
        int len = 0;
        while (produtos[i].nome[len] != '\0') len++;
        if (len > 0 && produtos[i].nome[len - 1] == '\n') {
            produtos[i].nome[len - 1] = '\0';
        }

        printf("Preço: ");
        scanf("%f", &produtos[i].preco);

        soma_precos += produtos[i].preco;

        printf("\n");
    }

    // Cálculo do preço médio
    float preco_medio = soma_precos / 3;

    // Exibir preço médio
    printf("Preço médio dos produtos: R$ %.2f\n", preco_medio);

    return 0;
}

