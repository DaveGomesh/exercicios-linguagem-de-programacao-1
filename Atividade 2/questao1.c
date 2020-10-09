#include <stdio.h>
#include <ctype.h>

#define eh_minuscula(letra) (isalpha(letra) ? (islower(letra) ? "Eh minuscula!" : "Nao eh minuscula...") : "Nao eh uma letra...")
/**
 * @author: David Gomesh
 * 
 * Macro: eh_minuscula(letra)
 * Funcao: verificar se determinada letra eh minuscula
 * 
 * Funcionamento: primeiramente, verifica se o que foi passado
 * eh uma letra, depois verifica se essa letra eh minuscula.
 * 
 * Caso nao seja uma letra, retorna "Nao eh uma letra".
 * Caso seja minuscula, retorna "Eh minuscula".
 * Caso nao seja minuscula, retorna "Nao eh minuscula".
 * 
*/

#define maiuscula(letra) (isalpha(letra) ? (islower(letra) ? letra = toupper(letra) : 0) : -1)
/**
 * @author: David Gomesh
 * 
 * Macro: maiuscula(letra)
 * Funcao: converte uma letra minuscula para maiuscula
 * 
 * Funcionamento: primeiramente, verifica se o que foi passado
 * eh uma letar, depois verifica se eh minuscula, e, por fim,
 * converte de minuscula para maiuscula.
 * 
 * Caso nao seja uma letra, retorna -1, significando que nao eh uma letra
 * Caso seja minuscula, retorna o codigo ascii da letra maiuscula
 * Caso nao seja minuscula, retorna 0, siginificando que ja eh maiuscula
 * 
*/

int main(){
    char letra;

    printf("Informe uma letra: ");
    scanf("%c", &letra);

    //a
    printf("Resultado: %s\n", eh_minuscula(letra));

    //b
    char letraMaiuscula = maiuscula(letra);

    printf("Resultado: ");

    if(letraMaiuscula != -1){
        if(letraMaiuscula != 0){
            printf("%c\n", letraMaiuscula);
        }
        else{
            printf("Ja eh maiuscula...\n");
        }
    }
    else{
        printf("Nao eh uma letra...\n");
    }

    return 0;
}

