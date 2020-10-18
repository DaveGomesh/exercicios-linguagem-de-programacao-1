#include <stdio.h>

void exibirRange(int numero){
    if(numero == 0){
        printf("\n");
        return;
    }
    else{
        printf("%i ", -numero);
        exibirRange(--numero);
        printf(" %i ", numero);
    }
}

int main(){
    exibirRange(123);
    return 0;
}