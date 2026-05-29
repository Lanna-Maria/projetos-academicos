#include <stdio.h>
int main() {
    int numeros[5];  // Declara um array de 5 números inteiros
    int *ptr = numeros;  // Aponta para o primeiro elemento do array
   
    for (int i = 0; i < 5; i++) {
        printf("Digite o %dº número: ", i + 1);  
        scanf("%d", &numeros[i]);  
    }

    // Exibição dos números usando ponteiro
    printf("Os números digitados foram: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i)); 
    }
    
    return 0;
}
