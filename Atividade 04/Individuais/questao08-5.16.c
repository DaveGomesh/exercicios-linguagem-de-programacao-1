#include <stdio.h>

void strcat(char strDestino[], char strOrigem[]);

int main(){
    static char string1[16] = "Facil";
    char string2[] = "idade";

    printf("String 1: %s\n", string1);
    printf("String 2: %s\n\n", string2);

    strcat(string1, string2);

    printf("String concatenadas: %s\n", string1);

    return 0;
}

void strcat(char strDestino[], char strOrigem[]){
    int tam=0;

    while(strDestino[tam]!='\0'){
        tam++;
    }

    for(int i=0; strOrigem[i]!='\0'; i++){
        strDestino[tam++] = strOrigem[i];
    }

    strDestino[tam] = '\0';
}