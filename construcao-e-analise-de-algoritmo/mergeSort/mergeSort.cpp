#include<stdio.h>
#include<stdlib.h>

// Definir a estrutura do nó da lista encadeada
struct Node {
    int data;
    struct Node* next;
};

// Função auxiliar para dividir a lista em duas partes
void splitList(struct Node* source, struct Node** frontRef, struct Node** backRef) {
    struct Node* slow = source;
    struct Node* fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

// Função auxiliar para combinar duas listas ordenadas em uma única lista ordenada
struct Node* mergeLists(struct Node* a, struct Node* b) {
    struct Node* result = NULL;

    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;

    if (a->data <= b->data) {
        result = a;
        result->next = mergeLists(a->next, b);
    } else {
        result = b;
        result->next = mergeLists(a, b->next);
    }

    return result;
}

// Função principal para ordenar a lista usando o Merge Sort
void mergeSort(struct Node** headRef) {
    struct Node* head = *headRef;
    struct Node* a;
    struct Node* b;

    if ((head == NULL) || (head->next == NULL))
        return;

    splitList(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = mergeLists(a, b);
}
struct Node* head = NULL;

// Código para preencher a lista com valores

mergeSort(&head);

// A lista agora está ordenada em ordem crescente



