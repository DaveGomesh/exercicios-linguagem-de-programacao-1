#include <stdio.h>
#include <string.h>

void converterParaInt(char numeroChar[], int numeroInt[]);
/**
 * @author: David Gomesh
 * 
 * Funcao responsavel por receber um vetor de caracteres
 * e converte-lo para um vetor de inteiros.
 * 
 * Essa funcao recebe o vetor de caractere e o vetor de inteiros
 * onde sera guardado os valores convertidos.
 * 
*/

int digitoVerificador(char numero[]);
/**
 * @author: David Gomesh
 * 
 * Funcao que calcula o digito verificador de um numero
 * de 9 digitos.
 * 
 * Essa funcao recebe um vetor de caracteres e usa a funcao
 * converterParaInt() para converter os caracteres para inteiro.
 * 
*/

int main(){
    char numeroChar[10];

    printf("Informe um numero: ");
    fgets(numeroChar, 10, stdin);

    printf("Digito verificador: %i\n", digitoVerificador(numeroChar));

    return 0;
}

void converterParaInt(char numeroChar[], int numeroInt[]){
    for(int i=0; i<9; i++){
        numeroInt[i] = numeroChar[i] - '0';
    }
}

int digitoVerificador(char numeroChar[]){
    //Vetor que guardara os digitos convertidos para int
    int numeroInt[9];

    int resultado1 = 0, resultado2;
    int digitoVerificador;

    converterParaInt(numeroChar, numeroInt);

    for(int i=0, j=10; j>=2; i++, j--){
        resultado1 += numeroInt[i] * j;
    }

    resultado2 = 11 - resultado1 % 11;

    if(resultado2 > 9){
        digitoVerificador = 0;
    }
    else{
        digitoVerificador = resultado2;
    }

    return digitoVerificador;
}