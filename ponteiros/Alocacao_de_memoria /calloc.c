#include <stdio.h>
#include <stdlib.h> 

int main(){

    //calloc aloca memória na heap (memória dinâmica)
    //A memória alocada por calloc é inicializada com 0
    //A memória alocada por calloc deve ser liberada com free quando não for mais necessária
    //calloc retorna um ponteiro do tipo void* que deve ser convertido para o tipo desejado
    //sizeof retorna o tamanho em bytes do tipo de dado informado


    int *ptr = (int*) calloc(10, sizeof(int)); //alocando espaço para 10 inteiros e inicializando com 0
    for(int i=5; i<10; i++){
        ptr[i] = i * 10; //inicializando os valores
    }
    for(int i=0; i<10;i++){
        printf("%d\n", ptr[i]); //imprimindo todos os valores
    }


    free(ptr);
    return 0;
}