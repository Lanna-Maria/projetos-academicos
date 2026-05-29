#include <stdio.h>
int main() {
    int numero = 10;
    int *p;
    p = &numero;
    printf("O valor da variável via ponteiro é: %d\n", *p);
    return 0;
}
