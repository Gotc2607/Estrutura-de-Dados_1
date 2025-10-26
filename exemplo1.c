#include <stdio.h>
#include <stdlib.h>

//usando isertion sort

// 1- alocar memoria para um vetor 
// 2- compor o vetor
// 3- ordenar esse vetor
// 4- usar busca binaria para procurar um elemento nesse vetor 
// 5- liberar a memoria alocada para o vetor

void Insertion_Sort(int *v, int n){
    for(int i = 1; i<n; i++){
        int chave = v[i];
        int j = i - 1;
        while(j >= 0 && v[j] > chave){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = chave;
    }
}

int busca_binaria(int *v, int n, int x){
    int inicio = 0;
    int fim = n-1;
    while(inicio <= fim){
        int meio = (inicio + fim)/2;

        if(v[meio] == x){
            return meio;
        }

        if(v[meio] < x){
            inicio = meio + 1;
        } 

        if(v[meio]>x){
            fim = meio -1;
        }
    }
    return -1;
}

int main(){
    
    int n;
    
    printf("Dihite o tamanho do array: ");
    scanf("%d", &n);
    
    int *v = (int *) malloc(n * sizeof(int));

    for(int i = 0; i<n; i++){
        printf("Digite o %d elemento: ", i);
        scanf("%d", &v[i]);
    }

    for(int i = 0; i<n;i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    int x;
    printf("Digite o numero que quer procurar: ");
    scanf("%d", &x);

    Insertion_Sort(v, n);

    for(int i = 0; i<n;i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    int indice = busca_binaria(v, n, x);
    if(indice == -1){
        printf("elemento não encontrado\n");
    }
    else{
        printf("Termo encontrado no indice %d\n", indice);
    }

    return 0;
}