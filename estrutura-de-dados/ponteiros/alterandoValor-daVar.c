#include <stdio.h>

int main() {
    int numero = 10;   
    int *p;             
    p = &numero;      

    printf("O valor original de 'numero' via ponteiro é: %d\n", *p);

    *p = 20;  
    
    printf("O novo valor de 'numero' via ponteiro é: %d\n", *p);

    return 0;
}
