#include <stdio.h>

float potencia(int base, int expoente);
/**
 * @author: David Gomesh
 * 
 * A Funcao recebe a base e o expoente para calcular a potencia.
 * 
 * Se o expoente for positivo, multplica a base pela propria base
 * pela quantidade de vezes que o expoente determinar.
 * 
 * Se o expoente for negativo, multica 1/base por 1/base
 * pela quantidade de vezes que o expoente determinar.
 * Para isso o expoente eh mulplicado por -1, para se tornar positivo.
 * 
*/

int main(){
    int base, expoente;

    printf("Base: ");
    scanf("%i", &base);
 
    printf("Expoente: ");
    scanf("%i", &expoente);

    printf("Potencia: %.6f\n", potencia(base, expoente));
    return 0;
}

float potencia(int base, int expoente){

    //Resultado a ser retornado
    float resultado = 1; 

    //Controla se expoente eh positivo ou negativo
    int expoentePositivo; 

    if(expoente > 0){
        expoentePositivo = 1;
    }
    else{
        expoentePositivo = 0;

        //Torna o expoente positivo caso seja negativo
        expoente *= -1; 
    }

    //O expoente controla quantas vezes sera repetido, por isso precisa ser positivo
    for(int i=0; i<expoente; i++){ 

        //Se o expoente for positivo, multiplica a base pelo resultado atual
        if(expoentePositivo){ 
            resultado *= base; 
        }

        //Se o expoente for negativo, o resultado eh multiplicado por (1/base)
        else{
            resultado *= ((float)1 / base);
        }
    }
    
    return resultado;
}