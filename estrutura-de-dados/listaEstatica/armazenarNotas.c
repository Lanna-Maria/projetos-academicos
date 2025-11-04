#include <stdio.h>
#define MAX 100

// Definição da estrutura da lista estática de notas
typedef struct {
    float notas[MAX]; // Vetor de float para armazenar as notas
    int tamanho; // Quantidade de notas armazenadas
} ListaEstatica;

// Inicializa a lista de notas
void inicializa(ListaEstatica *lista) {
    lista->tamanho = 0;
}

// Insere uma nova nota na lista
void insere(ListaEstatica *lista, float nota) {
    if (lista->tamanho < MAX) {
        lista->notas[lista->tamanho++] = nota;
    } else {
        printf("Lista de notas cheia!\n");
    }
}

// Exibe todas as notas da lista
void exibe(ListaEstatica lista) {
    printf("Notas:\n");
    for (int i = 0; i < lista.tamanho; i++) {
        printf("%.2f ", lista.notas[i]);
    }
    printf("\n");
}

// Busca uma nota específica
int busca(ListaEstatica lista, float nota) {
    for (int i = 0; i < lista.tamanho; i++) {
        if (lista.notas[i] == nota) {
            return i;
        }
    }
    return -1;
}

// Remove uma nota específica
void removeNota(ListaEstatica *lista, float nota) {
    int pos = busca(*lista, nota);
    if (pos == -1) {
        printf("Nota %.2f não encontrada.\n", nota);
        return;
    }
    for (int i = pos; i < lista->tamanho - 1; i++) {
        lista->notas[i] = lista->notas[i + 1];
    }
    lista->tamanho--;
    printf("Nota %.2f removida.\n", nota);
}

// Função principal de demonstração
int main() {
    ListaEstatica lista;
    inicializa(&lista);

    // Inserindo algumas notas
    insere(&lista, 7.5);
    insere(&lista, 8.0);
    insere(&lista, 6.3);
    insere(&lista, 9.1);

    exibe(lista);

    // Buscando uma nota
    float notaBusca = 8.0;
    int pos = busca(lista, notaBusca);
    if (pos != -1) {
        printf("Nota %.2f encontrada na posição %d.\n", notaBusca, pos);
    } else {
        printf("Nota %.2f não encontrada.\n", notaBusca);
    }

    // Removendo uma nota
    removeNota(&lista, 6.3);
    exibe(lista);

    // Tentando remover uma nota inexistente
    removeNota(&lista, 10.0);

    return 0;
}

