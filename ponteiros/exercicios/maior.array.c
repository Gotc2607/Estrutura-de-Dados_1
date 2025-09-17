#include <stdio.h>

void maior_elemento(int *V, int tamanho, int *maior){

    *maior = *V; //inicializando maior com o primeiro elemento do array
    for(int i=0; i<tamanho; i++){
        if(*(V+i)>*maior){
            *maior = *(V+i); //atualizando maior se encontrar um elemento maior
        }
    }
}

int main(){

    int x, maior = 0;
    scanf("%d", &x);

    int V[x];
    for(int i=0; i<x; i++){
        scanf("%d", &V[i]); //lendo os valores do array
    }

    maior_elemento(V, x, &maior);
    printf("Maior elelemento: %d\n", maior);


    return 0;
}