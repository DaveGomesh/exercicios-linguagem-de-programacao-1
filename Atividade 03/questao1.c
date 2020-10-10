#include <stdio.h>

int ocorrencias(unsigned int numero, int digito);
/**
 * @author: David Gomesh
 * 
 * Basicamente, quando a funcao ser chamada,
 * os digitos dos numeros serao analisados de tras pra frente.
 * Ou seja, primero o digito das unidades, dps das dezenas...
 * 
 * Enquanto o numero passado a funcao for diferente de zero,
 * a recursividade vai acontecer.
 * 
 * Caso o digito analisado seja igual ao digito informado a funcao,
 * ocorrencia() eh invocada novamente, com o numero divido por 10
 * e do seu retorno sera adicionado 1.
 * 
 * Caso contrario, a mesma coisa acontece, mas o nao sera adicionado
 * nada ao seu retorno, uma vez que esse digito nao sera contabilizado.
 *    
*/

int main(){
    unsigned int numero;
    int digito;

    printf("Informe um numero: ");
    scanf("%ui", &numero);

    printf("Informe o digito: ");
    scanf("%i", &digito);

    printf("Ocorrencias: %i\n", ocorrencias(numero, digito));

    return 0;
}

int ocorrencias(unsigned int numero, int digito){
    if(numero != 0){
        if(numero % 10 == digito){
            return ocorrencias(numero/10, digito) + 1;
        }
        else{
            return ocorrencias(numero/10, digito);
        }
    }
    else{
        return 0;
    }
}