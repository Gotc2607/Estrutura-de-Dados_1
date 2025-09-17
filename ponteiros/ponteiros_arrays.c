#include <stdio.h>

int main(){

    //O nome de um array(vetor) é um ponteiro para o primeiro elemento do array
    int V[5];
    for(int i=0; i<5; i++){
        V[i] = i + 1; //inicializando o array com valores de 1 a 5
    }
    for(int i=0; i<5; i++){
        if(V[i] == 3){
            printf("achei o 3\n");
            break;
        }
    }

    int *ptr = V; //o ponteiro está apontando para o primeiro elemento de V (V[0])
    //int *ptr = &V[0]; //outra forma de fazer a mesma coisa

    printf("%d\n", *ptr); //Imprime o primeiro elemento do array (1)
    *ptr = *ptr +10; //Adiciona 10 ao primeiro elemento do array
    printf("%d\n", *ptr); //Imprime o primeiro elemento do array (11)

    printf("%d\n", *(ptr+1)); //Imprime o segundo elemento do array (2)

    for(int i=0; i<5; i++){
        printf("%d\n", *(ptr+i)); //Imprime todos os elementos do array
    }

    return 0;
}