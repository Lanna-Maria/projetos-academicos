#include <stdio.h>

int main() {
    int numeros[6]; 
    int *ptr = numeros;  
    int count = 0;

    printf("Digite 6 números inteiros:\n");
    for (int i = 0; i < 6; i++) {
        scanf("%d", &numeros[i]); 
    }

    // Contando os números pares utilizando o ponteiro
    for (int i = 0; i < 6; i++) {
        if (*(ptr + i) % 2 == 0) {  
            count++; 
        }
    }

    printf("Quantidade de números pares: %d\n", count);
    
    return 0;
}


