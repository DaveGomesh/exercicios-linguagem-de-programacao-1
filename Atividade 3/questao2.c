#include <stdio.h>

void converterParaBinario(int numero);
/**
 * @author David Gomesh
 * 
 * A funcao ira imprimir, nao guardar, o numero
 * na base binaria.
 * 
 * Ela ira ficar se invocando (recursivamente), passando
 * sempre o numero dividido por 2, ate que esse numero seja zero,
 * pois esse eh o caso trivial.
 * 
 * Chegando no ultimo caso, a funcoes se encerram exibindo
 * o resto da divisao do seu numero atual por 2.
 * 
 * Obs.: caso o primeiro numero passado seja zero, a funcao nao ira
 * imprimir nada, pois nao existe resto de divisao no calculo 0/2.
 * Ha varias formas de contornar esse problema, mas para simplificar
 * o codigo, resolvi fazer um simples teste na funcao main mesmo.
 *     
*/

int main(){
    int numero;

    printf("Informe um numero decimal: ");
    scanf("%i", &numero);

    printf("Numero em Binario: ");

    if(numero != 0){
        converterParaBinario(numero);
        printf("\n");
    }
    else{
        printf("0\n");
    }

    return 0;
}

void converterParaBinario(int numero){
    if(numero != 0){
        converterParaBinario(numero/2);
        printf("%i", numero%2);
    }
    else{
        return;
    }
}