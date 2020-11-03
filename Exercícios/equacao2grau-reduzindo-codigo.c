#include <stdio.h>
#include <math.h>
int equacao2grau(float coeficientes[], float raizes[]){
    raizes[0] = (coeficientes[1] * coeficientes[1]) - 4 * coeficientes[0] * coeficientes[2] > 0 ? raizes[0] = (-coeficientes[1] + sqrt((coeficientes[1] * coeficientes[1]) - 4 * coeficientes[0] * coeficientes[2])) / (2 * coeficientes[0]) : 0.0; 
    raizes[1] = (coeficientes[1] * coeficientes[1]) - 4 * coeficientes[0] * coeficientes[2] == 0 ? 0.0 : (-coeficientes[1] - sqrt((coeficientes[1] * coeficientes[1]) - 4 * coeficientes[0] * coeficientes[2])) / (2 * coeficientes[0]);
    return (coeficientes[1] * coeficientes[1]) - 4 * coeficientes[0] * coeficientes[2] < 0 ? 0 : (coeficientes[1] * coeficientes[1]) - 4 * coeficientes[0] * coeficientes[2] == 0 ? 1 : 2;
}
int main(){
    static float coeficientes[3], raizes[2], quantRaizes; // Quantidade de raizes
    for(int i=0; i<4 && (i<3 ? printf("Valor de '%c': ", i+97) : 1) != 0 && (i<3 ? scanf("%f", &coeficientes[i]) : 1) != 0; i++) i==3 ? coeficientes[0] == 0 ? printf("Nao eh uma equacao do 2 grau!\n") : (quantRaizes=equacao2grau(coeficientes, raizes)) >= 1 ? printf(quantRaizes == 1 ? "Quantidade de raizes reais: %.0f\nResultado X: %.2f\n" : "Quantidade de raizes reais: %.0f\nResultado X1: %.2f\nResultado X2: %.2f\n", quantRaizes, raizes[0], quantRaizes == 1 ? 0 : raizes[1]) : printf("Nao possui raizes reais\n") : 0;
    return 0;
}