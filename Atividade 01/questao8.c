#include <stdio.h>

int main(){
    int numero;

    printf("Informe um numero diferente de zero: ");
    scanf("%i", &numero);

    //Calcula a quantidade de asteriscos na base da piramide
    //O valor da base também é o valor da largura da piramide
    int base = numero * 2 - 1;

    // Controla a altura da piramide
    for(int linha=0; linha<numero; linha++){ 

        // Controla onde sera o proximo asterisco na altura atual
        int posicaoProximoAsterisco=(base/2)-linha;

        // Controla a largura da piramide
        for(int coluna=0, quantAsteriscos=0; coluna<base; coluna++){ 

            // Se a coluna for a coluna do proximo asterisco
            if(coluna == posicaoProximoAsterisco){

                printf("*");
                quantAsteriscos++;

                // (linha * 2 + 1): é quantidade de asteriscos que essa linha pode ter
                if(quantAsteriscos < (linha * 2 + 1)){
                    posicaoProximoAsterisco++;
                }
                else{
                    // Esse valor negativo serve apenas para que nenhum asterisco seja coloca depois da quantidade maxima de asteriscos em deteminada altura/linha
                    posicaoProximoAsterisco=-1;
                }

            }
            else{
                // Colocando 'printf("-");' pode se ver melhor como a piramide foi montada
                // printf("-");
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

/*
    Linha 0 -> Quant. de asteriscos: 1  [ Expressão: 1  * 2 - 1 ]
    Linha 1 -> Quant. de asteriscos: 3  [ Expressão: 3  * 2 - 1 ]
    Linha 2 -> Quant. de asteriscos: 5  [ Expressão: 5  * 2 - 1 ]
    Linha 3 -> Quant. de asteriscos: 7  [ Expressão: 7  * 2 - 1 ]
    Linha 4 -> Quant. de asteriscos: 9  [ Expressão: 9  * 2 - 1 ]
    Linha 5 -> Quant. de asteriscos: 11 [ Expressão: 11 * 2 - 1 ]
    Linha 6 -> Quant. de asteriscos: 13 [ Expressão: 13 * 2 - 1 ]
    Linha 7 -> Quant. de asteriscos: 15 [ Expressão: 15 * 2 - 1 ]
    Linha 8 -> Quant. de asteriscos: 17 [ Expressão: 17 * 2 - 1 ]
*/