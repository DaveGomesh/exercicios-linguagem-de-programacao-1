#include <stdio.h>

void selecao(char v[]){
    int i,k,x,j;
    for(i=0;i<8;i++){
        k=i;
        for(j=i+1; j<9; j++){
            if(v[k]>=v[j]){
                k=j;
            }
        }
        x = v[i];
        v[i] = v[k];
        v[k] = x;
    }
}

int main(){
    char L[9] = {'u','o','d','z','w','k','a','b','j'};

    for(int j=0;j<9;j++){
        printf("%c ", L[j]);
    }
    printf("\n");

    selecao(L);

    for(int j=0;j<9;j++){
        printf("%c ", L[j]);
    }
}
