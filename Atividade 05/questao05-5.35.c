#include <stdio.h>



int selmin(int v[], int i){
    int j, k=i;
    for(j=i+1; j<9; j++)
        if(v[k]>v[j])
            k=j;
    return k;
}

void selecao(int v[]){
    int i,k,x;
    for(i=0;i<8;i++){
        k = selmin(v,i);
        x = v[i];
        v[i] = v[k];
        v[k] = x;
    }

    for(int j=0;j<8;j++){
        printf("%d ", v[j]);
    }


}




int main(){
int L[9] = {82,50,71,63,85,43,39,97,14};
int i=0;
selecao(L);
}
