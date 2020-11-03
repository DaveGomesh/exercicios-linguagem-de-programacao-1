#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "campominado.h"

void exibirMenu();
void jogar(int dificuldade);
void exibirInstucoes();
int  definirDificuldade(int dificuldade);

int main(){
    srand(time(NULL));
    int opcao, dificuldade=FACIL;

    do{
        //Inicia a função que exibe o menu
        exibirMenu();
        printf("\nOPCAO: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                //Caso o numero 1 seja digitado, será iniciado o jogo
                jogar(dificuldade);
                break;
            
            case 2:
                //Caso o numero 2 seja digitado, será mostrada as instruções do jogo
                exibirInstucoes();
                break;
            
            case 3:
                //Caso o numero 3 seja digitado, será definida a dificuldade
                dificuldade = definirDificuldade(dificuldade);
                break;

            case 4:
                //Caso o numero 4 seja digitado, o programa se encerrará
                printf("\n-----JOGO ENCERRADO-----\n");
                break;
            
            default:
                printf("\nOpcao Invalida!!!\n");
        }
    
    }while(opcao != 4);

    return 0;
}

//Função que exibe o Menu
void exibirMenu(){
    system("cls");

    printf("----------------------------\n");
    printf("        CAMPO MINADO        \n");
    printf("----------------------------\n");
    printf("\n\n");

    printf("GAME MENU\n");
    printf("1 - INICIAR\n");
    printf("2 - INSTRUCOES\n");
    printf("3 - DIFICULDADE\n");
    printf("4 - SAIR\n");
}

//Funcao que inicia o jogo
void jogar(int dificuldade){
    Jogo campoMinado;
    int resultado;

    system("cls");

    //Chama a função que inicializa e gera o campo
    incializarCampoMinado(&campoMinado, dificuldade);
    //Chama a função que mostra o campo     
    exibirCampo(&campoMinado);

    do{
        resultado = fazerJogada(&campoMinado);

        system("cls");
        exibirCampo(&campoMinado);

        switch(resultado){
            case -1:
                printf("\nCoordenadas Invalidas!\n");                
                break;

            case  0:
                system("cls");
                exibirCampo(&campoMinado);
                printf("\nVoce perdeu!\n");

                break;    
        }

    }while(resultado != -2 && resultado != 0);

    system("pause");
}

//Funcao que exibe as instrucoes
void exibirInstucoes(){
    system("cls");

    printf("INSTRUCOES:\n\n");

    printf("Em Campo Minado seu OBJETIVO eh escolher as casas onde NAO tem bombas!\n\n");

    printf("Atraves das casas que possuem numros ao redor, voce guiara suas escolhas...\n\n");

    printf("COMANDOS: Voce devera digitar a linha e a coluna da casa que voce queira escolher.\n");
    printf("Por exemplo: 1,2 (Linha 1 e Coluna 2), e assim revelera o que ha nessa casa!\n\n");

    printf("Se houver bomba, voce perdera o jogo.\n");
    printf("Se nao, dira a quantidade de bombas que possuem ao redor desta casa.\n\n");

    printf("\nNo mais, BOM GAME :)\n\n");

    system("pause");
}

// Funcao que define a dificuldade
int definirDificuldade(int dificuldade){
    int opcao=0;

    do{
        system("cls");
        printf("DIFICULDADE ATUAL: %d BOMBAS\n", dificuldade);

        printf("ESCOLHA A DIFICULDADE:\n");
        printf("1 - FACIL(10 BOMBAS)\n");
        printf("2 - MEDIO(20 BOMBAS)\n");
        printf("3 - DIFICIL(30 BOMBAS)\n");
        printf("0 - VOLTAR\n");

        printf("\nOPCAO: ");
        scanf(" %d", &opcao);

        switch(opcao){
            case 1:
                dificuldade = FACIL;
                break;

            case 2:
                dificuldade = MEDIO;
                break;
            
            case 3:
                dificuldade = DIFICIL;
                break;

            case 0:
                break;

            default:
                printf("\nOpcao Invalida!\n");
        }
    }while(opcao <= 1 && opcao >= 3);

    printf("\n---Definido!---\n");

    system("pause");

    return dificuldade;
}