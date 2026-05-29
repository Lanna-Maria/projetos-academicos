#include <stdio.h>

// Definição da struct Funcionario
struct Funcionario {
    char nome[50];
    int id;
    float salario;
};

int main() {
    struct Funcionario funcionarios[5];

    // Cadastro dos 5 funcionários
    for (int i = 0; i < 5; i++) {
        printf("Cadastro do funcionário %d\n", i + 1);

        printf("Nome: ");
        getchar(); // limpar buffer antes do fgets (para i > 0)
        fgets(funcionarios[i].nome, 50, stdin);
        // remover '\n'
        int len = 0;
        while (funcionarios[i].nome[len] != '\0') len++;
        if (len > 0 && funcionarios[i].nome[len - 1] == '\n') {
            funcionarios[i].nome[len - 1] = '\0';
        }

        printf("ID: ");
        scanf("%d", &funcionarios[i].id);

        printf("Salário: R$ ");
        scanf("%f", &funcionarios[i].salario);

        printf("\n");
    }

    // Aumentar salário em 10%
    for (int i = 0; i < 5; i++) {
        funcionarios[i].salario *= 1.10f;
    }

    // Exibir dados atualizados
    printf("--- Dados Atualizados dos Funcionários ---\n");
    for (int i = 0; i < 5; i++) {
        printf("Funcionário %d\n", i + 1);
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("ID: %d\n", funcionarios[i].id);
        printf("Salário atualizado: R$ %.2f\n\n", funcionarios[i].salario);
    }

    return 0;
}

