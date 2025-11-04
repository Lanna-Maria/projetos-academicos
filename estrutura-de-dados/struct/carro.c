#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da struct Carro
struct Carro {
    char modelo[50];
    int ano;
    float preco;
};

int main() {
    int N;

    printf("Quantos carros deseja cadastrar? ");
    scanf("%d", &N);
    getchar();  // limpar buffer

    // Alocação dinâmica para N carros
    struct Carro *carros = (struct Carro *) malloc(N * sizeof(struct Carro));
    if (carros == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    // Cadastro dos carros
    for (int i = 0; i < N; i++) {
        printf("\nCadastro do carro %d\n", i + 1);

        printf("Modelo: ");
        fgets(carros[i].modelo, 50, stdin);
        carros[i].modelo[strcspn(carros[i].modelo, "\n")] = '\0';  // remove \n

        printf("Ano: ");
        scanf("%d", &carros[i].ano);

        printf("Preço: R$ ");
        scanf("%f", &carros[i].preco);
        getchar();  // limpar buffer
    }

    // Mostrar todos os carros cadastrados
    printf("\n--- Todos os carros cadastrados ---\n");
    for (int i = 0; i < N; i++) {
        printf("Carro %d:\n", i + 1);
        printf("Modelo: %s\n", carros[i].modelo);
        printf("Ano: %d\n", carros[i].ano);
        printf("Preço: R$ %.2f\n\n", carros[i].preco);
    }

    // Mostrar carros com preço menor que 50.000
    printf("--- Carros com preço menor que R$ 50.000 ---\n");
    int achou = 0;
    for (int i = 0; i < N; i++) {
        if (carros[i].preco < 50000.0) {
            printf("Carro %d:\n", i + 1);
            printf("Modelo: %s\n", carros[i].modelo);
            printf("Ano: %d\n", carros[i].ano);
            printf("Preço: R$ %.2f\n\n", carros[i].preco);
            achou = 1;
        }
    }

    if (!achou) {
        printf("Nenhum carro com preço menor que R$ 50.000 encontrado.\n");
    }

    free(carros); // liberar memória

    return 0;
}
