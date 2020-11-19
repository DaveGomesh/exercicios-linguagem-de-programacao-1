#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 100
#define TAMANHO 40000

int selmin(int v[], int i){
    int j, k=i;
    for(j=i+1; j<TAMANHO; j++)
        if(v[k]>v[j])
            k=j;
    return k;
}

void trocas(int v[]){
    int i, j;
    for(i=1; i<TAMANHO;i++){
        for(j=0;j<TAMANHO-i;j++){
            if(v[j]>v[j+1]){
                int x = v[j];
                v[j] = v[j+1];
                v[j+1] = x;
            }
        }
    }
}

void selecaoMin(int v[]){
    int i,k,x;
    for(i=0;i<TAMANHO-1;i++){
        k = selmin(v,i);
        x = v[i];
        v[i] = v[k];
        v[k] = x;
    }
}

void selecao(int v[]){
    int i,k,x,j;
    for(i=0;i<TAMANHO-1;i++){
        k=i;
        for(j=i+1; j<TAMANHO; j++){
            if(v[k]>v[j]){
                k=j;
            }
        }
        x = v[i];
        v[i] = v[k];
        v[k] = x;
    }
}

void insercao(int lista[]){
    int j, elem;
    
    for(int i=1; i<TAMANHO; i++){

        elem = lista[i];

        for(j=i-1; j>=0 && elem < lista[j]; j--){
            lista[j+1] = lista[j];
        }

        lista[j+1] = elem;
    }
}

int main(){
    srand(time(NULL));
    clock_t Ticks[2];

    int milliseconds;
    int seconds;
    int minutes;

    double time1;
    double time2;
    double time3;
    double time4;

    int lista1[TAMANHO];
    int lista2[TAMANHO];
    int lista3[TAMANHO];
    int lista4[TAMANHO];

    for(int i=0; i<TAMANHO; i++){
        lista1[i] = lista2[i] = lista3[i] = lista4[i] = rand() % NUM;
    }

    // for(int i=0; i<TAMANHO; i++){
    //     printf("%i ", lista1[i]);
    // }
    // printf("\n");
    // for(int i=0; i<TAMANHO; i++){
    //     printf("%i ", lista2[i]);
    // }
    // printf("\n");
    // for(int i=0; i<TAMANHO; i++){
    //     printf("%i ", lista3[i]);
    // }
    // printf("\n");
    // for(int i=0; i<TAMANHO; i++){
    //     printf("%i ", lista4[i]);
    // }
    // printf("\n");

    Ticks[0] = clock();
    trocas(lista1);
    Ticks[1] = clock();
    
    time1 = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    milliseconds = (int) time1 % 1000;
    seconds = (int) (time1 / 1000) % 60;
    minutes = (int) (time1 / 60000) % 60;
    printf("Tempo de Trocas(): %i:%i:%i (min:seg:mil)\n\n", minutes, seconds, milliseconds);

    Ticks[0] = clock();
    selecaoMin(lista2);
    Ticks[1] = clock();

    time2 = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    milliseconds = (int) time2 % 1000;
    seconds = (int) (time2 / 1000) % 60;
    minutes = (int) (time2 / 60000) % 60;
    printf("Tempo de selecaoMin(): %i:%i:%i (min:seg:mil)\n\n", minutes, seconds, milliseconds);

    Ticks[0] = clock();
    selecao(lista3);
    Ticks[1] = clock();

    time3 = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    milliseconds = (int) time3 % 1000;
    seconds = (int) (time3 / 1000) % 60;
    minutes = (int) (time3 / 60000) % 60;
    printf("Tempo de selecao(): %i:%i:%i (min:seg:mil)\n\n", minutes, seconds, milliseconds);

    Ticks[0] = clock();
    insercao(lista4);
    Ticks[1] = clock();

    time4 = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    milliseconds = (int) time4 % 1000;
    seconds = (int) (time4 / 1000) % 60;
    minutes = (int) (time4 / 60000) % 60;
    printf("Tempo de insercao(): %i:%i:%i (min:seg:mil)\n\n", minutes, seconds, milliseconds);

    // for(int i=0; i<TAMANHO; i++){
    //     printf("%i ", lista1[i]);
    // }
    // printf("\n");
    // for(int i=0; i<TAMANHO; i++){
    //     printf("%i ", lista2[i]);
    // }
    // printf("\n");
    // for(int i=0; i<TAMANHO; i++){
    //     printf("%i ", lista3[i]);
    // }
    // printf("\n");
    // for(int i=0; i<TAMANHO; i++){
    //     printf("%i ", lista4[i]);
    // }
    // printf("\n");
    return 0;
}