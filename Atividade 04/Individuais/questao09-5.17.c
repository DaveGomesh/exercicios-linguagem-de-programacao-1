#include <stdio.h>

int strpos(char string[], char caractere);

int main(){
    char string[] = "Linguagem C"; //11
    char caractere = 'C';

    printf("String: %s\n", string);
    printf("O caractere %c esta na posicao %i\n", caractere, strpos(string, caractere));

    return 0;
}

int strpos(char string[], char caractere){
    int i=0;

    for(i=0; string[i]!='\0'; i++){
        if(string[i]==caractere){
            return i;
        }
    }

    return -1;
}