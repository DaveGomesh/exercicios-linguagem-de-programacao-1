#include <stdio.h>

#define MAX 7

void exibirTemps(float temps[]);
void obtemTemps(float temps[]);
float mediaTemps(float temps[]);
int contarTempsAcimaMedia(float temps[], float media);

int main(){
    static float temps[7];
    float media;
    int quant;

    obtemTemps(temps);
    // exibirTemps(temps);
    media = mediaTemps(temps);
    quant = contarTempsAcimaMedia(temps, media);

    printf("\nMedia de Temperatura: %.1f%cC\n", media, 248);
    printf("Quant. acima da Media: %i temps\n", quant);

    return 0;
}

void exibirTemps(float temps[]){
    for(int i=0; i<MAX; i++){
        printf("Temp %i: %.1f%cC\n", i+1, temps[i], 248);
    }
}

void obtemTemps(float temps[]){
    for(int i=0; i<MAX; i++){
        printf("Temp %i: ", i+1);
        scanf(" %f", &temps[i]);
    }
}

float mediaTemps(float temps[]){
    float soma=0.0;

    for(int i=0; i<MAX; i++){
        soma += temps[i];
    }

    return soma/MAX;
}

int contarTempsAcimaMedia(float temps[], float media){
    int cont=0;

    for(int i=0; i<MAX; i++){
        if(temps[i] > media){
            cont++;
        }
    }

    return cont;
}