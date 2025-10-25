#include <stdio.h>


void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Selection_Sort(int *v, int n, int inicio){

    if(inicio >= n-1){
        return;
    }

    int menor = inicio; // assumindo que o menor elemento é o primeiro
    for(int i = inicio + 1; i<n; i++){
        if(v[i]<v[menor]){
            menor = i; //atualizando o menor elemento
        }
    }

    if(menor != inicio){
        troca(&v[inicio], &v[menor]); // trocando o menor elemento com o primeiro
    }

    Selection_Sort(v, n, inicio + 1); //chamamos ela novamente para ela ordenar a outra parte do vetor

}

int main(){

    int v[] = {7 ,1 , 4, 3, 2, 8};
    int n = sizeof(v)/sizeof(v[0]); // calcula  o tamanho do vetor usando sizeof

    Selection_Sort(v, n, 0); // a primeira chamada deve ser com o inicio igual a 0

    for(int i =0; i < n; i++){
        printf("%d ", v[i]);
    }


    return 0;
}