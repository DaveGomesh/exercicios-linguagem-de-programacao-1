#include <stdio.h>
#include <stdlib.h>

#include "questao1.h"
#include "questao2.h"

void exibirMenuPrincipal(int * opcao);

void exibirQuestao1();
void exibirQuestao2();

int main(){
    int opcao;

    do{
        exibirMenuPrincipal(&opcao);

        switch(opcao){
            case 1:
                exibirQuestao1();
                break;

            case 2:
                exibirQuestao2();
                break;

            case 0:
                printf("\nAdeus....\n\n");
                system("pause");
                break;
            
            default:
                printf("\nOpcao invalida!!!\n\n");
                system("pause");
                break;
        }
    }while(opcao != 0);

    return 0;
}

void exibirMenuPrincipal(int * opcao){
    system("cls");

    printf("-----TESTAR FUNCOES-----\n");
    printf("1 - Inverter numeros\n");
    printf("2 - Converter de Binario para Decimal\n");
    printf("0 - Sair\n\n");

    printf("OPCAO: ");
    scanf("%i", opcao);
}

void exibirQuestao1(){
    system("cls");
    int numero, numeroInvertido;

    printf("\nINVERTER NUMEROS\n\n");

    printf("Prototipo: 'int inverterNumero(int numero)'\n");

    printf("Descricao: Recebe um numero inteiro qualquer e retorna esse numero inteiro invertido.\n\n");

    printf("Por exemplo, digite um numero: ");
    scanf(" %i", &numero);

    numeroInvertido = inverterNumero(numero);

    printf("Invertendo o numero obtemos:   %i\n\n", numeroInvertido);

    printf("Eh importante ressaltar que esse numero gerado eh um inteiro.\n");
    printf("Ou seja, podera ser feito calculos normalmente com ele, como uma variavel comum.\n\n");

    printf("Por exemplo: %i + 1 = %i\n\n", numeroInvertido, numeroInvertido+1);

    system("pause");
}

void exibirQuestao2(){
    system("cls");
    int numeroBinario, numeroDecimal;

    printf("\nCONVERTER DE BINARIO PARA DECIMAL\n\n");

    printf("Prototipo: 'int binarioParaDecimal(unsigned int numero)'\n");

    printf("Descricao: Recebe um numero na base binaria e o retorna convertido na base decimal.\n\n");

    printf("Por exemplo, digite um numero binario: ");
    scanf("%i", &numeroBinario);

    numeroDecimal = binarioParaDecimal(numeroBinario);

    printf("Convertendo para Decimal obtemos: %i\n\n", numeroDecimal);

    printf("Eh importante ressaltar que esse numero gerado eh um inteiro.\n");
    printf("Ou seja, podera ser feito calculos normalmente com ele, como uma variavel comum.\n\n");

    printf("Por exemplo: %i + 1 = %i\n\n", numeroDecimal, numeroDecimal+1);

    system("pause");
}