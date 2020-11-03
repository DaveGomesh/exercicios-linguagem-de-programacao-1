#ifndef CAMPOMINADO_H_INCLUDED
#define CAMPOMINADO_H_INCLUDED

// Bibliotecas incluidas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Dimensoes maximas das matrizes
#define MAX_LIN 10
#define MAX_COL 10

// Dificuldades do jogo: quantidade de bombas
#define FACIL   10
#define MEDIO   20
#define DIFICIL 30

// Constantes importantes
#define PAREDE  -1
#define OCULTO   0
#define EXIBINDO 1
#define VAZIO    0
#define BOMBA    9

// Estrutura de coordenadas
typedef struct tipo_coordenadas{
    int lin;
    int col;
}Coordenadas;

// Estrutura do jogo
typedef struct tipo_jogo{
    int campo[MAX_LIN][MAX_COL]; //Armazenas as bombas e os numeros
    int visualizacao[MAX_LIN][MAX_COL]; //Controla o que sera exibido
    int dificuldade; //Controla a dificuldade do jogo: quant de bombas
}Jogo;

// Declaração de funcoes
void gerarParedes(Jogo * campoMinado);
void inicializarExibicao(Jogo * campoMinado);
void incializarCampoMinado(Jogo * campoMinado, int dificuldade);
void revelarBombas(Jogo * campoMinado);
void analisarEspacos(Jogo * campoMinado, Coordenadas coord);
int  fazerJogada(Jogo * campoMinado);


// Colocas as paredes nas matrizes
void gerarParedes(Jogo * campoMinado){
    for(int lin=0; lin<MAX_LIN; lin++){ //Percorrera todas as linhas
        if(lin==0 || lin==MAX_LIN-1){ //Se for a primeira ou a ultima, coloca as paredes em toda linha
            for(int col=0; col<MAX_COL; col++){
                campoMinado->campo[lin][col] = PAREDE;
                campoMinado->visualizacao[lin][col] = PAREDE;
            }
        }
        else{ //Senao, coloca as paredes apenas na primeira e na ultima coluna
            campoMinado->campo[lin][0] = PAREDE;
            campoMinado->visualizacao[lin][0] = PAREDE;

            campoMinado->campo[lin][MAX_COL-1] = PAREDE;
            campoMinado->visualizacao[lin][MAX_COL-1] = PAREDE;
        }
    }
}

// Zera todas as posicoes das matrizes
void inicializarMatrizes(Jogo * campoMinado){
    for(int i=1; i<MAX_LIN-1; i++){
        for(int j=1; j<MAX_COL-1; j++){
            campoMinado->campo[i][j] = VAZIO;
            campoMinado->visualizacao[i][j] = OCULTO;
        }
    }
}

// Gera as bombas do jogo
void gerarBombas(Jogo * campoMinado){
    int quantBombas=0, numAleatorio;
    int lin, col;

    while(quantBombas < campoMinado->dificuldade){
        //Gera posicoes aleatorias entre 1 e a posicao maxima
        lin = 1 + rand() % MAX_LIN-2;
        col = 1 + rand() % MAX_COL-2;

        if(campoMinado->campo[lin][col] == VAZIO){ //Se nao tiver bomba, coloca uma bomba
            campoMinado->campo[lin][col] = BOMBA; //9 == Bomba
            quantBombas++;
        }
    }
}

// Gera os numeros que indicam a quantidade de bombas ao redor deles
void gerarNumeros(Jogo * campoMinado){
    int quantBombas;

    //Percorre todo o campo
    for(int lin=1; lin<MAX_LIN-1; lin++){
        for(int col=1; col<MAX_COL-1; col++){

            if(campoMinado->campo[lin][col] != BOMBA){ //Se nao tiver bombas
                quantBombas=0;

                //Percorre em volta do local selecionado
                for(int i=lin-1; i<=lin+1; i++){
                    for(int j=col-1; j<=col+1; j++){

                        if(campoMinado->campo[i][j] == BOMBA){ //Se no local atual tiver bombas
                            quantBombas++; //Aumenta a quantidade de bombas encontradas
                        }

                    }
                }

                //Coloca a quantidade de bombas encontradas no local selecionado
                campoMinado->campo[lin][col] = quantBombas;
            }

        }
    }
}

// Exibe o campo minado todo formatado/personalizado
void exibirCampo(Jogo * campoMinado){
    //Percorre toda a matriz do campo
    //Tera uma linha a mais na exibicao, pois deve haver espacos para os numeros
    //E
    for(int lin=-1; lin<MAX_LIN; lin++){
        for(int col=0; col<MAX_COL; col++){

            //Coloca os numeros das colunas na primeira linha da exibicao
            if(lin==-1){
                if(col>0&&col<MAX_COL-1){
                    printf("%i ", col);
                }
                else{
                    printf("   ");
                }

                continue;
            }

            /* BORDAS */
            //Canto superior esquerdo
            if(lin==0 && col==0){
                printf(" %c%c", 201, 205);
                continue;
            }

            //Canto superior direito
            if(lin==0 && col==MAX_COL-1){
                printf("%c", 187);
                continue;
            }

            //Canto inferior direito
            if(lin==MAX_LIN-1 && col==MAX_COL-1){ 
                printf("%c", 188);
                continue;
            }

            //Canto inferior esquerdo
            if(lin==MAX_LIN-1 && col==0){ 
                printf(" %c%c", 200, 205);
                continue;
            }
            
            /* BARRAS */
            // Barras horizontais
            if((col>0 && col<MAX_COL-1) && (lin==0 || lin==MAX_LIN-1)){
                printf("%c%c", 205, 205);
                continue;
            }

            // Barras verticais
            if((lin>0 && lin<MAX_LIN-1) && (col==0 || col==MAX_COL-1)){ 
                if(col==MAX_COL-1){
                    printf("%c ", 186);
                }
                else{
                    //Aproveita para colocar o numero das linhas
                    printf("%i%c ", lin, 186);
                }

                continue;
            }

            /* CONTEUDO DA MATRIZ */
            //Se estiver aberto para mostrar
            if(campoMinado->visualizacao[lin][col] == EXIBINDO){

                //Se tiver bomba
                if(campoMinado->campo[lin][col]==BOMBA){
                    printf("%c ", 207);
                }
                // Se tiver numeros
                else{
                    printf("%i ", campoMinado->campo[lin][col]);
                }

                continue;
            }

            //Se estiver oculto
            if(campoMinado->visualizacao[lin][col]==OCULTO){
                printf("%c ", 254);
                continue;
            }

        }

        printf("\n");
    }
}

// Faz todos os procedimentos necessarios para inicializar o jogo
void incializarCampoMinado(Jogo * campoMinado, int dificuldade){
    campoMinado->dificuldade = dificuldade;
    gerarParedes(campoMinado);
    inicializarMatrizes(campoMinado);
    gerarBombas(campoMinado);
    gerarNumeros(campoMinado);
}

// Revela a posicao de todas as bombas do jogo
void revelarBombas(Jogo * campoMinado){
    //Percorre toda a matrix procurando as bombas
    for(int lin=1; lin<MAX_LIN; lin++){
        for(int col=1; col<MAX_COL; col++){
            if(campoMinado->campo[lin][col]==BOMBA){
                campoMinado->visualizacao[lin][col] = EXIBINDO;
            }
        }
    }
}

// Analisa os espacos a serem exibidos apos uma jogada
void analisarEspacos(Jogo * campoMinado, Coordenadas coord){
    int i, j;
    //Percorre em volta do local selecionado
    for(i=coord.lin-1; i<=coord.lin+1; i++){
        for(j=coord.col-1; j<=coord.col+1; j++){
            //Se o local atual estiver vazio
            if(campoMinado->campo[i][j]==VAZIO){
                //Se a visualizacao estiver oulta
                if(campoMinado->visualizacao[i][j]==OCULTO){
                    campoMinado->visualizacao[i][j] = EXIBINDO;

                    Coordenadas novasCoord;
                    novasCoord.lin = i;
                    novasCoord.col = j;

                    //Chama novamente, para um nova analise em um nova posicao
                    analisarEspacos(campoMinado, novasCoord);
                }
            }
            //Apenas exibe se nao for uma bomba ou um numero diferente de zero
            else if(campoMinado->campo[i][j]!=BOMBA){
                campoMinado->visualizacao[i][j] = EXIBINDO;
            }
        }
    }
}

// Inicia uma nova jogada e retorna algo com base na jogada
int fazerJogada(Jogo * campoMinado){
    int lin, col;

    printf("Informe a linha: ");
    scanf("%i", &lin);

    printf("Informe a coluna: ");
    scanf("%i", &col);

    //Verifica se foi digitado as posicoes de saida
    if(lin==0 && col==0){
        revelarBombas(campoMinado);
        return -2;
    }

    //Verifica se eh uma coordenada invalida
    if(lin <= 0 || col <= 0 || lin >= MAX_LIN-1 || col >= MAX_COL-1){
        return -1;
    }

    //Verifica se eh uma bomba
    if(campoMinado->campo[lin][col] == BOMBA){
        revelarBombas(campoMinado);
        return 0;
    }

    //Verifica se o local esta vazio
    if(campoMinado->campo[lin][col] == VAZIO){
        campoMinado->visualizacao[lin][col] = EXIBINDO;

        //Cria variaveis para enviar as coordenadas
        Coordenadas coord;
        coord.lin = lin;
        coord.col = col;

        //Envia as coordenadas para analise
        analisarEspacos(campoMinado, coord);
        return 1;
    }

    //Verifica se tem um numero diferente de zero
    if(campoMinado->campo[lin][col] >= 1 || campoMinado->campo[lin][col] <= 8){
        campoMinado->visualizacao[lin][col] = EXIBINDO;
        return 1;
    }

}

#endif /*CAMPOMINADO_H_INCLUDED */