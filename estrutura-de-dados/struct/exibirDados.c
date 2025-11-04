#include <stdio.h>

// Definição da struct Data
struct Data {
    int dia;
    int mes;
    int ano;
};

// Definição da struct Evento
struct Evento {
    char descricao[100];
    struct Data data_evento;
};

int main() {
    struct Evento evento;

    // Leitura da descrição do evento
    printf("Digite a descrição do evento: ");
    fgets(evento.descricao, 100, stdin);

    // Remove o \n do final da string, se existir
    size_t len = 0;
    for (len = 0; evento.descricao[len] != '\0'; len++) {}
    if (len > 0 && evento.descricao[len - 1] == '\n') {
        evento.descricao[len - 1] = '\0';
    }

    // Leitura da data do evento
    printf("Digite o dia do evento: ");
    scanf("%d", &evento.data_evento.dia);
    printf("Digite o mês do evento: ");
    scanf("%d", &evento.data_evento.mes);
    printf("Digite o ano do evento: ");
    scanf("%d", &evento.data_evento.ano);

    // Exibição dos dados do evento
    printf("\n--- Dados do Evento ---\n");
    printf("Descrição: %s\n", evento.descricao);
    printf("Data: %02d/%02d/%04d\n", evento.data_evento.dia, evento.data_evento.mes, evento.data_evento.ano);

    return 0;
}

