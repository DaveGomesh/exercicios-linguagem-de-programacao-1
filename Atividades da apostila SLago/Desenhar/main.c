#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>

#include "jogo.h"
#include "console.h"

int main(){

    Jogo jogo;
    inicializarJogo(&jogo);

    while(1){
        jogo.tecla.controle = getch();
        jogo.tecla.teclaAtual = getch();

        switch(jogo.tecla.controle){
            // Movimento
            case 224:
                movimentar(&jogo);
                break;

            // Comandos
            case 0:
                menuComandos(&jogo);
                break;
        }
    }

    return 0;
}