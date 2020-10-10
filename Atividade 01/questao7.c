#include <stdio.h>

int main(){
    int numero;
    int controle = 1;

    do{
        printf("Informe um numero: ");
        scanf("%i", &numero);

        switch(controle){
            case 1: //Esperado positivos
                if(numero > 0){
                    printf("Aceito: %i\n", numero);
                    controle = 0;
                }
                else if(numero < 0){
                    printf("Rejeitado: %i\n", numero);
                }

                break;

            case 0: //Esperado negativos
                if(numero < 0){
                    printf("Aceito: %i\n", numero);
                    controle = 1;
                }
                else if(numero > 0){
                    printf("Rejeitado: %i\n", numero);
                }

                break;
        }
    }while(numero != 0);
                
    printf("Zero digitado!\n");

    return 0;
}