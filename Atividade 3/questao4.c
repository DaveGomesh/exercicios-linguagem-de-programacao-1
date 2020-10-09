#include <stdio.h>

int maximoDivisorComum(int num1, int num2);
/**
 * @author: David Gomesh
 * 
 * Seguindo as intrucoes da questao, a funcao foi criada.
 * 
 * E no ultimo caso, se X for igual a Y o resultado sera o
 * proprio X ou o proprio Y, pois eles tem valores iguais.
 * 
*/

int main(){
    int num1, num2;

    printf("Informe o numero 1: ");
    scanf("%i", &num1);

    printf("Informe o numero 2: ");
    scanf("%i", &num2);

    printf("Result: %i\n", maximoDivisorComum(num1, num2));

    return 0;
}

int maximoDivisorComum(int num1, int num2){
    if(num1 > num2){
        return maximoDivisorComum(num1 - num2, num2);
    }
    else if(num1 < num2){
        return maximoDivisorComum(num2, num1);
    }
    else{ //Caso num1 == num2
        return num1;
    }

}