#include <stdio.h>
#include <locale.h> 

void losango(int l) { // l = losango
    int i, j, k; // variável k é para os asteriscos 

    // metade superior do losango
    for (i = 0; i < l; i++) {
        // espaços em branco antes do losango 
        for (j = 0; j < l - i - 1; j++) { 
            printf(" "); 
        }
        // asteriscos do losango
        for (k = 0; k < 2 * i + 1; k++) { 
            printf("*"); 
        }
        printf("\n"); 
    }

    // metade inferior do losango
    for (i = l - 2; i >= 0; i--) { 
        // espaços em branco antes do losango
        for (j = 0; j < l - i - 1; j++) { 
            printf(" "); 
        }
        // asteriscos do losango
        for (k = 0; k < 2 * i + 1; k++) { 
            printf("*"); 
        }       printf("\n"); 
    }
}

int main() { //função principal
	setlocale(LC_ALL, "Portuguese"); 
    int res; 
    printf("Digite o tamanho do losango: "); 
    scanf("%d", &res);
    losango(res); 
    return 0;
}

