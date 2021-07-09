#include <stdio.h>
#include <stdlib.h>

void insercao(int v[], int n){
    int i, j, x;

    for(i=1; i<n; i++){
        x = v[i];

        for(j=i-1; j>=0 && x<v[j]; j--){
            v[j+1] = v[j];
        }
        
        v[j+1] = x;
    }
}

int main(){
    int lista[] = {10, 9, 8};
    int tam = 3;

    insercao(lista, tam);

    return 0;
}