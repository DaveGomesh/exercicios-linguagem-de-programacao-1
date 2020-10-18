#include "jogo.h"

int main(){
    Jogo jogo;

    inicializarVariaveis(&jogo);

    iniciarJogo(&jogo);

    // detalharJogo(&jogo);

    return 0;
}

/*
    Tentativa
    Dizer se errou ou acertou
    Dizer se o chute foi maior ou menor que o numero
    facil = 20 chances, medio = 15, dificil = 6;
    escolher a quantidade de tentativas
    Nao pode ter numeros negativos
    todo jogador começa com 1.000 pontos. A cada rodada, subtraímos desse número a diferença entre o número secreto e o chute, dividido por 2.
    nao pode jogar o mesmo numero
*/