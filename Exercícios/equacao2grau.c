#include <stdio.h>
#include <math.h>

int equacao2grau(float a, float b, float c, float * x1, float * x2);

int main(){
    float a, b, c; // Coeficientes
    float x1, x2; // Raizes
    int quantRaizes; // Quantidade de raizes

    printf("Valor de 'a': ");
    scanf("%f", &a);
    
    printf("Valor de 'b': ");
    scanf("%f", &b);

    printf("Valor de 'c': ");
    scanf("%f", &c);

    if(a == 0){
        printf("Nao eh uma equacao do 2 grau!\n");
        return -1;
    }

    quantRaizes = equacao2grau(a, b, c, &x1, &x2);

    printf("Quantidade de raizes reais: %i\n", quantRaizes);

    if(quantRaizes > 0){
        printf("Resultado X1: %.2f\n", x1);

        if(quantRaizes == 2){
            printf("Resultado X2: %.2f\n", x2);
        }
    }

    return 0;
}

int equacao2grau(float a, float b, float c, float * x1, float * x2){
    float delta;

    delta = (b * b) - 4 * a * c;

    if(delta < 0){ //Nao tem raizes reais
        return 0;
    }

    * x1 = (-b + sqrt(delta)) / (2 * a); // Primeira raiz

    if(delta == 0){ // 1 raiz real
        return 1;
    }
    
    * x2 = (-b - sqrt(delta)) / (2 * a); // Segunda raiz

    if(delta > 0){ // 2 raizes reais
        return 2;
    }
}