#include <stdio.h>

int strlen(char string[]);

int main(){
    char string[] = "Linguagem C"; //tam = 11

    printf("String: %s\n", string);
    printf("Tamanho: %i\n", strlen(string));

    return 0;
}

int strlen(char string[]){
    int tam=0;

    while(string[tam]!='\0'){
        tam++;
    }

    return tam;
}