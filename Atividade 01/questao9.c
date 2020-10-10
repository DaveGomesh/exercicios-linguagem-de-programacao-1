#include <stdio.h>

int main(){
    int numero;
    printf("Informe um numero: ");
    scanf("%i", &numero);

    for(int i=0; i<numero; i++){
        for(int j=0; j<numero; j++){

            // Se estiver na primeira linha ou na ultima
            // ou
            // Se estiver na primeira coluna ou na ultima
            if((i == 0 || i==numero-1) || (j == 0 || j==numero-1)){
                printf("*");
            }
            else{
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}