#include <stdio.h>
#include <stdlib.h>

//usando selection sort

// 1- alocar memoria para um vetor 
// 2- compor o vetor
// 3- ordenar esse vetor
// 4- usar busca binaria para procurar um elemento nesse vetor 
// 5- liberar a memoria alocada para o vetor

void troca(int *a, int *b){
    int  temp = *a;
    *a = *b;
    *b = temp;
}

void Selection_Sort(int *v, int n, int inicio){

    if(inicio < n - 1){
        int menor = inicio;
        for(int j = inicio; j<n-1; j++){
            if(v[j] < v[menor]){
                menor = j;
            }
        }

        if(menor != inicio){
            troca(&v[inicio], &v[menor]);
        }
        
        Selection_Sort(v, n, inicio + 1);


    }
}

int busca_binaria(int *v, int n, int x){
    int inicio = 0;
    int fim = n-1;

    while(inicio <= fim){
        int meio = (inicio + fim)/ 2;

        if(v[meio] == x){
            return meio;
        }

        if(v[meio]<x){
            inicio = meio +1;
        }

        if(v[meio] > x){
            fim = meio - 1;
        }
    }

    return -1;
}


int main(){

    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int *v = (int *) malloc(n * sizeof(int));

    for(int i = 0; i<n; i++){
        scanf("%d", &v[i]);
    }

    Selection_Sort(v, n, 0);

    for(int i = 0; i<n; i++){
        printf("%d ", v[i]);
    }

    int x;
    printf("Digite o elemento que deseja procurar: ");
    scanf("%d", &x);

    int indice = busca_binaria(v, n, x);

    if(indice == -1){
        printf("Elemento %d não encontrado no vetor.\n", x);
    }
    else{
        printf("Elemento %d encontrado no índice %d.\n", x, indice);
    }

    return 0;
}