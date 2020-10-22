/**
 * @author David Gomesh 
 * 
 * A funcao recebe um valor na base binaria qualquer e retorna esse valor
 * convertido na base decimal.
 * 
*/

#ifndef QUESTAO2_H_INCLUDED
#define QUESTAO2_H_INCLUDED

#include <math.h>

int binarioParaDecimal(unsigned int numeroBinario){
    static int expoente      = 0;
    static int numeroDecimal = 0;

    if(numeroBinario != 0){
        int digitoAtual = numeroBinario % 10;
        numeroDecimal += (digitoAtual * pow(2, expoente++));
        return binarioParaDecimal(numeroBinario/10);   
    }
    else{
        expoente=0;
        int resultado = numeroDecimal;
        numeroDecimal = 0;
        return resultado;
    }
}

#endif /* QUESTAO2_H_INCLUDED */