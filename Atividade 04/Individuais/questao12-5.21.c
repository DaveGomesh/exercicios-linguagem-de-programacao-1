#include <stdio.h>
#include <ctype.h>

void removerEnters(char nome[]){
    for(int i=0; nome[i]!='\0'; i++){
        if(nome[i]=='\n'){
            for(int j=i; nome[j]!='\0'; j++){
                nome[j] = nome[j+1];
            }
        }
    }
}

int main(){
    int tam = 6; //Tamanho da matriz quadrada
    char nomes[tam][tam];

    for(int i=0; i<tam-1; i++){
        gets(nomes[i]);
        /*
            Testar: Marta, Julio, Jonas, Rildo, Julio
        */
    }

    for(int i=0; i<tam-1; i++){
        for(int j=0; j<tam-1; j++){
            if(j == i){
                printf("%c", toupper(nomes[i][j]));
            }
            else{
                printf("-");
            }
        }

        printf("\n");
    }

    return 0;
}