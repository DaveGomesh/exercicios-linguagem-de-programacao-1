#include <stdio.h>

void converterParaInt(char numeroChar[], int numeroInt[]);
/**
 * @author: David Gomesh
 * 
 * Funcao responsavel por receber um vetor de caracteres
 * e converte-lo para um vetor de inteiros.
 * 
 * Na decima posicao do vetor resultante eh colocado -1 
 * para representar a ausencia de um digito verificador.
 * 
 * Esse -1 sera util para informar a funcao verificarDigitoVerificador()
 * se eh para verificar o primeiro ou o segundo digito verificador.
 * 
*/

int verificarCPF(char numeroCPF[], int digitosVerificadores);
/**
 * @author: David Gomesh
 * 
 * Funcao responsavel pelo controle da opercao de 
 * verificar o CPF.
 * 
 * Isto eh, ira chamar outras funcao necessarias,
 * ira fazer ajustes nos dados fornecidos, alem de retornar
 * 1 se o CPF for compativel com os digitos passados,
 * ou 0 se nao for.
 * 
*/

int verificarDigitoVerificador(int numeroCPF[], int digitoVerificador);
/**
 * @author: David Gomesh
 * 
 * Essa funcao apenas verifica digitos. Ele eh a que vai realmente
 * fazer a verificacao.
 * 
 * Ela consegue calcular tanto o primeiro quanto o segundo digito
 * verificador. Para saber qual digito calcular, ela verifica a decima
 * posicao do vetor onde esta guardado os caracteres.
 * 
 * Se tiver -1, eh verificado o primeiro digito verificador.
 * Se tiver qualquer coisa diferente de -1, verifica-se o segundo digito,
 * assumindo que o que esta na decima posicao eh o primeiro digito verificador.
 *  
*/

int main(){
    char numeroCPF[10];
    int digitosVerificadores;

    printf("Informe o numero do CPF: ");
    fgets(numeroCPF, 10, stdin);

    printf("Informe os digitos verificadores: ");
    scanf("%i", &digitosVerificadores);

    printf("CPF %s", verificarCPF(numeroCPF, digitosVerificadores) ? "valido!\n" : "invalido!\n");

    return 0;
}

void converterParaInt(char numeroChar[], int numeroInt[]){
    int i;
    for(i=0; i<9; i++){
        numeroInt[i] = numeroChar[i] - '0';
    }

    // Coloca -1 na decima posicao, indicando que os digitos verificadores estao ausentes
    numeroInt[i] = -1;
}

int verificarCPF(char numeroCPFChar[], int digitosVerificadores){

    // Armazenara os digitos do CPF como int
    int numeroCPFInt[10];

    int digitoVerificador1;
    int digitoVerificador2;

    // Resultados das verificacoes dos digitos
    int resultado1;
    int resultado2;

    converterParaInt(numeroCPFChar, numeroCPFInt);

    /*
        O primeiro digito verificador eh salvo dividindo os digitos por 10, 
        pois as dezenas representam o primeiro digito.

        No segundo, pegamos o resto da divisao, resultando no numero das
        unidades, que representam o segundo digito. 
    */
    digitoVerificador1 = digitosVerificadores / 10;
    digitoVerificador2 = digitosVerificadores % 10;

    // Verifica os dois digitos verificadores
    resultado1 = verificarDigitoVerificador(numeroCPFInt, digitoVerificador1);
    resultado2 = verificarDigitoVerificador(numeroCPFInt, digitoVerificador2);

    // Se ambos os resultados forem 1, entao retorna 1, pois o CPF eh valido
    return resultado1 && resultado2 ? 1 : 0;
}

int verificarDigitoVerificador(int numeroCPF[], int digitoVerificador){

    // Resultados dos passos para gerar os digitos verificadores
    int resultado1 = 0;
    int resultado2;

    int digitoVerificadorGerado;

    /*
        Primeiro passo para obter o digito verificador

        obs.: se o numeroCPF na posicao 9 (a decima) tiver '-1', 
        entende-se que deve se gerar o primeiro digito verificador, por isso j recebera 10.
        Caso tenha algo diferente de '-1',
        entende-se que deve se gerar o segundo digito verificador, por isso j recebera 11.
    */
    for(int i=0, j=numeroCPF[9] == -1 ? 10 : 11; j>=2; i++, j--){
        resultado1 += numeroCPF[i] * j;
    }

    // Segundo passo para obter o digito verificador
    resultado2 = 11 - resultado1 % 11;

    // Terceiro passo para obter o digito verificador
    digitoVerificadorGerado = resultado2 > 9 ? 0 : resultado2;

    /*
        O digito gerado eh guardado no numeroCPF.

        obs.: se o numeroCPF na posicao 9 tiver '-1',
        entende-se que o digito gerado eh o primeiro digito verificador.
        Caso tenha algo diferente de '-1',
        entende-se que o digito gerado eh o segundo digito verificador.
        O segundo digito nao sera utilizado, por isso nao eh guardado.
    */
    numeroCPF[numeroCPF[9] == -1 ? 9 : 10] = digitoVerificadorGerado;

    // Retorna 1 se o digito gerado for igual ao digito passado
    // E 0 caso seja diferente
    return digitoVerificadorGerado == digitoVerificador ? 1 : 0;
}