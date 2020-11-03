#include <stdio.h>

#define QUANT_CEDULAS 13

void quantidadeDeCelulas(float valor){
    static float valorCedulas[] = {0.01, 0.05, 0.1, 0.25, 0.5, 1, 2, 5, 10, 20, 50, 100, 200};
    static int i = QUANT_CEDULAS - 1;

    if(i >= 0 && valor > 0){
        int quant = valor/valorCedulas[i];

        if( quant!=0){

            printf("%i %s%sde R$%.2f\n", 
                quant, 
                valorCedulas[i] >= 2 ? "cedula" : "moeda", 
                quant > 1 ? "s " : " ", 
                valorCedulas[i]
            );

            valor -= valorCedulas[i] * quant;
        }

        i--;
        quantidadeDeCelulas(valor);
    }
    else{
        i = QUANT_CEDULAS - 1;
    }
}

int main(){
    float valor;

    printf("Informe um valor: ");
    scanf("%f", &valor);

    quantidadeDeCelulas(valor);


    return 0;
}