#include <stdio.h>

void soma_array(int *p, int tamanho, int *resultado){

    *resultado = 0; //inicializando o resultado
    for(int i=0; i<tamanho; i++){
        *resultado += *(p + i); //somando os valores do array
    }

}

int main(){

    int x, resultado = 0;
    scanf("%d", &x);
    
    int V[x];
    for(int i=0; i<x; i++){
        scanf("%d", &V[i]); //lendo os valores do array
    }

    soma_array(V, x, &resultado); //passando o array e o tamanho para a função
    printf("Soma: %d\n", resultado); //imprimindo o resultado



    return 0; 
}