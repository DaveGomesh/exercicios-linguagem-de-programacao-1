#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FACIL         1
#define MEDIO         2
#define DIFICIL       3
#define PERSONALIZADO 0

#define MAX_TENTATIVAS_FACIL   20
#define MAX_TENTATIVAS_MEDIO   15
#define MAX_TENTATIVAS_DIFICIL 5

#define VITORIA 1
#define DERROTA 0

#define MAX_PONTOS 1000

#define AUSENTE -1

typedef struct tipo_jogo{
    int numeroSecreto;
    int resultado;
    int dificuldade;
    int maxTentativas;
    int quantTentativas;
    int ultimaTentativa;
    int pontos;
}Jogo;

void inicializarVariaveis(Jogo * jogo){
    srand(time(NULL));
    rand() % 100;

    jogo->numeroSecreto   = rand() % 100;
    jogo->resultado       = AUSENTE;
    jogo->dificuldade     = FACIL;
    jogo->maxTentativas   = MAX_TENTATIVAS_FACIL;
    jogo->quantTentativas = 0;
    jogo->ultimaTentativa = AUSENTE;
    jogo->pontos          = MAX_PONTOS;
}

void detalharJogo(Jogo * jogo){
    printf("\n\nDETALHANDO O JOGO ATUAL\n\n");
    printf("Numero secreto       : %i\n", jogo->numeroSecreto);
    printf("Resultado            : %s\n", jogo->resultado == -1 ? "AUSENTE(-1)" : jogo->resultado ? "VITORIA(1)" : "DERROTA(0)");
    printf("Dificuldade          : %s\n", jogo->dificuldade == FACIL ? "FACIL" : jogo->dificuldade == MEDIO ? "MEDIO" : jogo->dificuldade == DIFICIL ? "DIFICIL" : "PERSONALIZADO");
    printf("Maximo de Tentativas : %i\n", jogo->maxTentativas);
    printf("Quant. de Tentativas : %i\n", jogo->quantTentativas);
    printf("Ultima tentativa     : %i\n", jogo->ultimaTentativa);
    printf("Total de Pontos      : %i\n", jogo->pontos);
}

void exibirMensagemBoasVindas(){
    printf("\n");

    printf("\t       P  /_\\  P \n");
    printf("\t      /_\\_|_|_/_\\ \n");
    printf("\t  n_n | ||. .|| | n_n    Bem-vindo ao\n");
    printf("\t  |_|_|nnnn nnnn|_|_|    Jogo da Adivinhacao!\n");
    printf("\t |' '  |  |_|  |'  ' | \n");
    printf("\t |_____| ' _ ' |_____| \n");
    printf("\t       \\__|_|__/");

}

void exibirOpcoesDificuldade(){
    printf("\n\n      Qual o nivel de dificuldade?\n");
    printf("      (1) Facil  (2) Medio  (3) Dificil\n");
    printf("      (0) Personalizado  OPCAO: ");
}

void definirQuantidadeTentativas(Jogo * jogo){
    switch(jogo->dificuldade){
        case FACIL:
            jogo->maxTentativas = MAX_TENTATIVAS_FACIL;
            break;

        case MEDIO:
            jogo->maxTentativas = MAX_TENTATIVAS_MEDIO;
            break;

        case DIFICIL:
            jogo->maxTentativas = MAX_TENTATIVAS_DIFICIL;
            break;
        
        case PERSONALIZADO:;
            int quantidadeTentativas;
            
            do{
                printf("\n      Informe a quantidade de tentativas: ");
                scanf("%i", &quantidadeTentativas);
            }while(quantidadeTentativas < 1);

            jogo->maxTentativas = quantidadeTentativas;
    }
}

void iniciarTentativas(Jogo * jogo){
    int chute;

    for(
        int i=0; 
        i<jogo->maxTentativas ; 
        i++
    ){
        system("cls");

        printf("      -> Tentativa %i de %i\n", i, jogo->maxTentativas);
        printf("      Chute um numero: ");
        scanf("%i", &chute);

        if(chute < 0 || chute > 99){
            printf("\n      Chute invalido!\n");
            printf("      Apenas numeros entre 0 - 99!\n\n");
            system("pause");
        }
        else if(chute == jogo->ultimaTentativa){
            i--;
            printf("\n      Voce chutou esse numero na ultima rodada!\n");
            printf("      Esse nao contara!\n\n");
            system("pause");
        }
        else{
            jogo->ultimaTentativa = chute;

            if(chute != jogo->numeroSecreto){
                printf("\n      Voce errou!\n");

                if(chute > jogo->numeroSecreto){
                    printf("      Voce chutou um numero maior que o numero secreto...\n");
                }
                else{
                    printf("      Voce chutou um numero menor que o numero secreto...\n");
                }

                printf("      Tente novamente...\n\n");

                system("pause");
            }
            else{
                jogo->resultado = VITORIA;
                exibirMensagemVitoria();
                system("pause");
                return;
            }
        }
    }

    jogo->resultado = DERROTA;
    exibirMensagemDerrota();
    system("pause");

}

void iniciarJogo(Jogo * jogo){
    int opcao;

    do{
        system("cls");

        exibirMensagemBoasVindas();
        exibirOpcoesDificuldade();
        scanf("%i", &opcao);

        switch(opcao){
            case 1:
            case 2:
            case 3:
            case 0:
                jogo->dificuldade = opcao;
                break;

            default:
                printf("\n      Opcao Invalida!\n");
                break;
        }
    }while(opcao < 0 || opcao > 3);

    definirQuantidadeTentativas(jogo);

    iniciarTentativas(jogo);
}

void exibirMensagemDerrota(){
    printf("\n");

    printf("\t     \\|/ ____ \\|/ \n");
    printf("\t      @~/ ,. \\~@ \n");
    printf("\t     /_( \\__/ )_\\ \n");
    printf("\t        \\__U_/ \n\n");

    printf("\t Voce perdeu! Tente novamente!");
}

void exibirMensagemVitoria(){
    printf("\n");
    printf("\t         0000000000000000         \n");
    printf("\t      0000000000000000000000      \n");
    printf("\t   000000000  00000  0000000000   \n");
    printf("\t  0000000000  00000  00000000000  \n");
    printf("\t  0000000000  00000  00000000000  \n");
    printf("\t  000000000000000000000000000000  \n");
    printf("\t  000000000000000000000000000000  \n");
    printf("\t  000000                  000000  \n");
    printf("\t  000000                  000000  \n");
    printf("\t   000000                 00000   \n");
    printf("\t    0000000             000000    \n");
    printf("\t      0000000         0000000     \n");
    printf("\t         00000000000000000        \n\n");

    printf("\t Parabens! Voce acertou! \n");
    printf("\t Voce fez 985.00 pontos. Ate a proxima!");
}

#endif /* JOGO_H_INCLUDED */