#include <stdio.h>
#include <ctype.h>

void diaRodizio(char placa[]);
/**
 * @author: David Gomesh
 * 
 * A funcao ira receber uma placa, que tera 3 letras e 4 numeros.
 * Porem apenas o ultimo caractere vai nos interessar.
 * 
 * Se o ultimo numero for par, a placa circulara em dias pares.
 * Se for impar, circulara em dias impares.
 * 
*/

int main(){
    char placa[8];

    printf("Informe a placa (ABC1234): ");
    fgets(placa, 8, stdin);

    printf("\nPlaca: %s\n", placa);

    diaRodizio(placa);

    return 0;
}

void diaRodizio(char placa[]){
    char ultimoCaractere = placa[6];
    int  ultimoNumero;

    if(isdigit(ultimoCaractere)){
        ultimoNumero = ultimoCaractere - '0';
        printf("Ultimo numero: %i\n\n", ultimoNumero);

        if(ultimoNumero%2 == 0){
            printf("Essa carro pode circular em dias pares!\n");
            
            printf("Nos dia: ");
            for(int dia=2; dia<=30; dia+=2){
                printf("%i ", dia);
            }
        }
        else{
            printf("Essa carro pode circular em dias impares!\n");

            printf("Nos dia: ");
            for(int dia=1; dia<=31; dia+=2){
                printf("%i ", dia);
            }
        }
    }
    else{
        printf("Ultimo caractere invalido: nao eh um numero!\n");
        return;
    }

}