#include <stdio.h>

int main(){
    int numeros[5];

    printf("Informe 5 numeros\n\n");

    for(int i=0; i<5; i++){
        printf("Numero %i: ", i+1);
        scanf("%i", &numeros[i]);
    }

    printf("\nNumeros na ordem inversa:\n");
    for(int i=4; i>=0; i--){
        printf("%i ", numeros[i]);
    }

    return 0;
}