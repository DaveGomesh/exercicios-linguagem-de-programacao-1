#include <stdio.h>

int quadradoNumero(int numero){
    static int quadrado=0, quantNumImpar=0, numImpar=1;

    if(quantNumImpar < numero){
        quadrado += numImpar;

        quantNumImpar++;
        numImpar += 2;

        return quadradoNumero(numero);
    }
    else
        return quadrado;
}

int main(){
    printf("%i", quadradoNumero(3));
    return 0;
}