#include <stdio.h>

void pertence(int testados[] , int lista[]){
    int inicio, fim, meio, k;
    inicio = 0;
    fim = 17;

    for(k=0;k<5;k++){

        while(inicio <= fim){

            meio = (inicio+fim)/2;


            if(testados[k] == lista[meio]){

                 printf("O numero %d pertence\n", testados[k]);

                 break;

                 }

            if (testados[k] > lista[meio]){

                fim = meio - 1;
            }

            else {

                inicio = meio + 1;

            }
        }

    inicio = 0;
    fim =  18;

    }


}



int main(){
    int L[18] = {99, 89, 84, 77, 72, 69, 68, 57, 53, 49, 41, 37, 33, 31, 27, 16, 10};
    int n[5];


    for(int i=0;i<5;i++){
        printf("Digite 5 numeros para rastrearmos: ");
        scanf("%d", &n[i]);
    }

    pertence(n,L);



}
