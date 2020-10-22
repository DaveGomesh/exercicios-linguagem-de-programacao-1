/**
 * @author David Gomesh 
 * 
 * A funcao recebe um numero inteiro qualquer e devolve esse numero
 * invertido. Esse numero retornado pode ser utilizado normalmente
 * como um variavel qualquer.
 * 
 * A variavael estatica 'i' será utlizada para multiplicar o novo
 * valor que as unidades guardarem por 1, depois o novo valor das
 * dezenas por 10, depois as centenas por 100... E assim por diante.
 * 
*/

#ifndef QUESTAO1_H_INCLUDED
#define QUESTAO1_H_INCLUDED

int inverterNumero(int numero){
    static float i        = 0.1;
    static int novoNumero = 0;

    if(numero != 0){
        int digitoAtual = numero % 10;
        inverterNumero(numero/10);
        return novoNumero += digitoAtual * (i*=10);
    }
    else{
        i=0.1;
        int resultado = novoNumero;
        novoNumero = 0;
        return resultado;
    }
}

#endif /* QUESTAO1_H_INCLUDED */