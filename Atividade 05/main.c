#include <stdio.h>

int main(){
    int num, quant=0;

    while(num != 9999){
        printf("Digite um numero: ");
        scanf("%i", &num);

        if(num > 0){
            quant++;
        }
    }

    printf("Quantidade de numeros positivos foi: %i\n", quant);
    return 0;
}