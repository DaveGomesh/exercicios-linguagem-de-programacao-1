#include <stdio.h>

void exibirRetangulo(int altura, int largura);
/**
 * @author: David Gomesh
 * 
 * A Funcao recebe altura e lagura e exibe um
 * retangulo com essa proporcoes.
 *  
*/

int main(){
    int altura, largura;

    printf("Altura: ");
    scanf("%i", &altura);

    printf("Largura: ");
    scanf("%i", &largura);

    exibirRetangulo(altura, largura);

    return 0;
}

void exibirRetangulo(int altura, int largura){
    for(int i=0; i<altura; i++){
        for(int j=0; j<largura; j++){
            printf("%c%c", 219, 219);
        }
        
        printf("\n");
    }
}