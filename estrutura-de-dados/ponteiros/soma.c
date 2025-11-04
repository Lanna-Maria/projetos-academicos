#include <stdio.h>
int main() {
    int numeros[5];  
    int *ptr = numeros;  
    int soma = 0;  

    for (int i = 0; i < 5; i++) {
        printf("Digite o %dº número: ", i + 1);  
        scanf("%d", &numeros[i]); 
    }

    for (int i = 0; i < 5; i++) {
        soma += *(ptr + i); 
    }

    printf("Soma: %d\n", soma);
    
    return 0;
}
