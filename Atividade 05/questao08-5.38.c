#include <stdio.h>

void insercao(int lista[]){
    int j, elem;
    
    for(int i=1; i<9; i++){

        elem = lista[i];

        for(j=i-1; j>=0 && elem < lista[j]; j--){
            lista[j+1] = lista[j];
        }

        lista[j+1] = elem;
    }
}

int main(){
    int lista[9] = {82, 50, 71, 63, 85, 43, 39, 97, 14};

    for(int i=0; i<9; i++){
        printf("%d ", lista[i]);
    }
    printf("\n");

    insercao(lista);
    
    for(int i=0; i<9; i++){
        printf("%d ", lista[i]);
    }

    return 0;
}