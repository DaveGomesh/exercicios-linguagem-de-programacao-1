#include <stdio.h>

int main(){
    char vogais[5] = {'a', 'e', 'i', 'o', 'u'};
    int temperaturas[7] = {32, 32, 31, 28, 33, 26, 31};
    int quantDiasMes[12] = {31, 28, 31, 30, 31, 30, 30, 31, 30, 31, 30, 31};

    //Exibindo
    //Vogais
    printf("VOGAIS:\n");
    for(int i=0; i<5; i++){
        printf("%c ", vogais[i]);
    }

    printf("\n\n");

    //Temperaturas
    printf("TEMPERATURAS:\n");
    for(int i=0; i<7; i++){
        printf("%i%cC ", temperaturas[i], 248);
    }

    printf("\n\n");

    //Quantidade de Dias de cada mes
    printf("QUANT. DIAS DE CADA MES:\n");
    for(int i=0; i<12; i++){
        printf("%i ", quantDiasMes[i]);
    }

    printf("\n\n");

    return 0;
}