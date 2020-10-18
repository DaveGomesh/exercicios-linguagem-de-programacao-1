#include <stdio.h>

void exibirTabuada(int numero){
    static int fator = 1;

    if(fator <= 10){
        printf("%i x %i = %i\n", numero, fator, numero*fator);
        fator++;
        exibirTabuada(numero);
    }
}

int main(){
    exibirTabuada(7);
    return 0;
}