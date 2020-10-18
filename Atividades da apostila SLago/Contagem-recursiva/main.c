#include <stdio.h>

void contagemRegressiva(int numero){
    if(numero == 0)
        return;
    else{
        printf("%i ", numero);
        contagemRegressiva(--numero);
    }
}

int main(){
    contagemRegressiva(8);

    return 0;
}