/**
 * 
 * @author David Gomes
 * @author Lucas Nadler
 * 
*/

#include <stdio.h>

int main(){
    char jogodavelha[3][3] = {' ', '0', 'X',
                              '0', 'X', '0',
                              'X', ' ', ' '};

    for(int altura=1, i=0; altura<=5; altura++){
        if(altura==2 || altura==4){
            printf("---+---+---\n");
        }
        else{
            for(int largura=1, j=0; largura<=11; largura++){
                if(largura==2 || largura==6 || largura==10){
                    printf("%c", jogodavelha[i][j++]);
                }
                else if(largura==4 || largura==8){
                    printf("|");
                }
                else{
                    printf(" ");
                }
            }
            printf("\n");
            i++;
        }
    }

    return 0;
}