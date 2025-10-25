// A busca binária funciona da seguinte forma:

// Ela busca um termo em um array usando como base o termo no meio do array
// O array precisa estar ordenado 

#include <stdio.h>

int Busca_binaria(int *v, int n, int x){
    int inicio = 0; // inicio do  array
    int fim = n-1;  // fim do array
    while(inicio <= fim){ // quando o inicio for maior que o fim o loop para

        int meio = (inicio + fim) / 2; //calculando o meio do array

        if(v[meio] == x){
            return meio;
        }

        if(v[meio] < x){
            inicio = meio + 1; // mudamos o meio de posição pois o x está para o seu lado direito
        }
        else{
            fim = meio - 1; // mudamos o meio de posição pois o x está para o seu lado esquerdo
        }
    }
    return -1; //caso o elemento não esteja no vetor retornamos -1
}