#include <stdio.h>

void strdel(char string[], char caractere);

int main(){
    char string[] = "Linguagem C+";

    printf("String original: %s\n", string);

    strdel(string, '+');

    printf("String nova: %s\n", string);

    return 0;
}

void strdel(char string[], char caractere){

    for(int i=0; string[i]!='\0'; i++){

        if(string[i]==caractere){

            while(string[i]!='\0'){
                string[i] = string[i+1];
                i++;
            }

            return;
        }
    }
}