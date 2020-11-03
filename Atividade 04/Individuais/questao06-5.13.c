#include <stdio.h>

void strcpy(char strDestino[], char strOrigem[]);

int main(){
    char string[] = "ola, terra!";

    printf("String original: %s\n", string);

    strcpy(string, "Ola, mundo!");

    printf("String nova    : %s\n", string);

    return 0;
}

void strcpy(char strDestino[], char strOrigem[]){
    for(int i=0; strOrigem[i]!='\0'; i++){
        strDestino[i] = strOrigem[i];
    }
}