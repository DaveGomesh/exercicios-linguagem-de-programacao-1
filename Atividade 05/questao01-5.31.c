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

            if (testados[k] < lista[meio]){

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
    int L[18] = {10,16,27,31,33,37,41,49,53,57,68,69,72,77,84,89,95,99};
    int n[5];


    for(int i=0;i<5;i++){
        printf("Digite 5 numeros para rastrearmos: ");
        scanf("%d", &n[i]);
    }

    pertence(n,L);



}
