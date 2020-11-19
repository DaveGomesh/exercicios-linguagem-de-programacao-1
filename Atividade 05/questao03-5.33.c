#include <stdio.h>





void trocas(int v[]){
    int i, j;
    for(i=1; i<9;i++){
        for(j=0;j<9-i;j++){
            if(v[j]>v[j+1]){
                int x = v[j];
                v[j] = v[j+1];
                v[j+1] = x;
            }
        }
    }
    for(int k=0; k<9;k++){
        printf("%d ", v[k]);
    }
}


int main(){

int L[9] = {92,80,71,63,55,41,39,27,14};

trocas(L);


}
