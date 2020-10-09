#include <stdio.h>

int modulo(int dividendo, int divisor);
/**
 * @author David Gomesh 
 * 
 * Seguindo as instrucoes da questao, quando o dividendo
 * for maior que o divisor, a funcao se invocara novamente,
 * passando o dividendo - divisor e o divisor.
 * 
 * Isso ira acontecer ate que o dividendo seja menor que o divisor,
 * nesse caso retornando o proprio dividendo. Ou quando eles forem iguais,
 * retornando zero como resultado.
 * 
*/

int main(){
    int dividendo, divisor;

    printf("Dividendo: ");
    scanf("%i", &dividendo);

    printf("Divisor: ");
    scanf("%i", &divisor);

    printf("Resultado: %i\n", modulo(dividendo, divisor));

    return 0;
}

int modulo(int dividendo, int divisor){
    if(dividendo > divisor){
        return modulo(dividendo - divisor, divisor);
    }
    else if(dividendo < divisor){
        return dividendo;
    }
    else{
        return 0;
    }
}