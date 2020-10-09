#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

#include <stdio.h>
#include <conio.h>

#include "console.h"

typedef struct tipo_configuracoes{
    int rastro;
    int borracha;
    int cor;
} Configuracoes;

typedef struct tipo_coordenadas{
    int coluna;
    int linha;
} Coordenadas;

typedef struct tipo_tecla{
    int controle;
    int teclaAtual;
} Tecla;

/*  TECLAS VALIDAS
    ============================================
    F2       : 60 (ativa e desativa o rastro)
    F3       : 61 (ativa e desativa a borracha)
    F4       : 62 (seleciona a cor)
    F5       : 63 (fim)
    Controle : 0
    --------------------------------------------
    Cima     : 72
    Direita  : 77
    Baixo    : 80
    Esquerda : 75
    Controle : 224
*/

typedef struct tipo_jogo{
    Tecla tecla;
    Coordenadas coordenadas;
    Configuracoes configuracoes;
} Jogo;

void deixarRastro(Jogo * jogo){
    gotoxy(jogo->coordenadas.coluna, jogo->coordenadas.linha);
    printf("%c", 219);
}

void alterarCor(Jogo * jogo, int cor){
    jogo->configuracoes.cor = cor;
    textcolor(cor);
}

void inicializarJogo(Jogo * jogo){
    /* Tecla */
    jogo->tecla.controle = 0;
    jogo->tecla.teclaAtual = 0;
    
    /* Coordenadas */
    jogo->coordenadas.coluna = 40;
    jogo->coordenadas.linha = 12;

    /* Configuracoes */
    jogo->configuracoes.borracha = 0;
    jogo->configuracoes.cor = LIGHTGREEN;
    jogo->configuracoes.borracha = 0;

    // Iniciando rastro
    textcolor(jogo->configuracoes.cor);
    deixarRastro(jogo);
}

void detalharjogo(Jogo * jogo){
    printf("DETALHAR JOGO\n");
    printf("Tecla de Controle: %i\n", jogo->tecla.controle);
    printf("Tecla Atual      : %i\n\n", jogo->tecla.teclaAtual);

    printf("COORDENADAS\n");
    printf("Coluna           : %i\n", jogo->coordenadas.coluna);
    printf("Linha            : %i\n\n", jogo->coordenadas.linha);

    printf("CONFIGURACOES\n");
    printf("Borracha         : %i\n", jogo->configuracoes.borracha);
    printf("Cor              : %i\n", jogo->configuracoes.cor);
    printf("Rastro           : %i\n", jogo->configuracoes.rastro);
}

void movimentar(Jogo * jogo){

    switch(jogo->tecla.teclaAtual){
        case 72: // Cima
            if(jogo->coordenadas.linha > 1){
                jogo->coordenadas.linha--;
            }
            break;
        
        case 77: // Direita
            if(jogo->coordenadas.coluna < 80){
                jogo->coordenadas.coluna++;
            }
            break;
        
        case 80: // Baixo
            if(jogo->coordenadas.linha < 24){
                jogo->coordenadas.linha++;
            }
            break;
        
        case 75: // Esquerda
            if(jogo->coordenadas.coluna > 1){
                jogo->coordenadas.coluna--;
            }
            break;
    }

    deixarRastro(jogo);
}

void ativar_desativarRastro(Jogo * jogo){
    // Em desenvolvimento
}

void modoBorracha(Jogo * jogo){
    switch(jogo->configuracoes.borracha){
        case 0:
            textcolor(BLACK);
            jogo->configuracoes.borracha = 1;
            break;
        
        case 1:
            alterarCor(jogo, jogo->configuracoes.cor);
            jogo->configuracoes.borracha = 0;
            break;
    }
}

void selecionarCor(Jogo * jogo){
    if(jogo->configuracoes.cor < 16){
        alterarCor(jogo, ++jogo->configuracoes.cor);
    }
    else if(jogo->configuracoes.cor == 16){
        jogo->configuracoes.cor = 0;   
        alterarCor(jogo, jogo->configuracoes.cor);
    }
}

void menuComandos(Jogo * jogo){
    switch(jogo->tecla.teclaAtual){
        case 60:
            ativar_desativarRastro(jogo);
            break;
        
        case 61:
            modoBorracha(jogo);
            break;

        case 62:
            selecionarCor(jogo);
            break;
    }
}

#endif /* JOGO_H_INCLUDED */