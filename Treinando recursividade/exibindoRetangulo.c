#include <stdio.h>

void exibirRetangulo(int altura, int largura){
    static int i=0, j=0;

    if(i<altura){
        
        if(j<largura){
            j++;
            printf("*");
            exibirRetangulo(altura, largura);
        }
        else{
            j=0;
            i++;
            printf("\n");
            exibirRetangulo(altura, largura);
        }
    }
}

int main(){
    exibirRetangulo(2,4);
    return 0;
}