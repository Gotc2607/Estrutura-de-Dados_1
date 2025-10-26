
#include <stdio.h>
#include <stdlib.h>

void intercala(int *v, int inicio, int meio, int fim){
    int i = inicio;
    int j = meio;
    int k = 0;

    int *temp = (int *)malloc((fim - inicio + 1) * sizeof(int)); //aloca memoria para um array do mesmo tamanho do original

    //Loop que compara as duas metades do array e copia o menor elemento para o vetor temporario
    while(i < meio && j < fim +1){ // enquanto os dois vetores tiverem elementos
        if ( v[i] <= v[j]){ // comparando os elementos dos dois vetores
            temp[k] = v[i]; // copiando o menor elemento para o vetor temporario
            k++, i++;
        }
        else{
            temp[k] = v[j]; // copiando o menor elemento para o vetor temporario
            k++, j++;
        }
    }
    
    //loop caso o maior elemento esteja na primeira metade do array
    while(i < meio){ // copiando o que sobrou do primeiro vetor
        temp[k++] = v[i++]; // copiando o que sobrou do primeiro vetor
    } 
    
    //loop caso o maior elemento esteja na segunda metade do array
    while(j < fim + 1){ // copiando o que sobrou do segundo vetor
        temp[k++] = v[j++]; // copiando o que sobrou do segundo vetor
    }
    
    //loop para copiar de volta o vetor temporario para o vetor original
    for(i = inicio, k = 0;i <= fim;i++, k++){ // copiando de volta para o vetor original
        v[i] = temp[k]; // copiando de volta para o vetor original
    }

    free(temp);
}
// complexidade O(n)

void MergeSort(int *v, int inicio, int fim){
    if (inicio < fim){
        int meio = (inicio + fim)/2;
        MergeSort(v, inicio, meio); // merge sort para a primeira parte do array

        MergeSort(v, meio + 1, fim); // merge sort para a segunda parte do array

        intercala(v, inicio, meio +1 , fim); // intercalando as duas metades do array
    }
}

int main(){

    int v[] = {38, 27, 43, 3, 9, 82, 10};

    int tamanho = sizeof(v)/sizeof(v[0]);

    MergeSort(v, 0, tamanho - 1);

    for(int i = 0; i < tamanho; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}