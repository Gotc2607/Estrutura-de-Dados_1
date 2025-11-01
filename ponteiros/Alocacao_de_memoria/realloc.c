#include <stdio.h>
#include <stdlib.h>

int main(){

    //realloc realoca memória previamente alocada por malloc ou calloc
    //Se a nova alocação for maior, o conteúdo antigo é preservado e o restante é não inicializado
    //Se a nova alocação for menor, o conteúdo é truncado
    //Se o ponteiro passado para realloc for NULL, ele se comporta como malloc
    //Se o tamanho passado para realloc for 0, ele se comporta como free
    //A memória realocada por realloc deve ser liberada com free quando não for mais necessária
    //realloc retorna um ponteiro do tipo void* que deve ser convertido para o tipo desejado
    //sizeof retorna o tamanho em bytes do tipo de dado informado

    int *ptr = (int*) malloc(5 * sizeof(int)); //alocando espaço para 5 inteiros
    for(int i=0; i<5; i++){
        ptr[i] = i * 10; //inicializando os valores
        printf("%d\n", ptr[i]); //imprimindo os valores
    }
    printf("Realocando memória para 10 inteiros\n");
    ptr = (int*) realloc(ptr, 10 * sizeof(int)); //realocando espaço para 10 inteiros
    for(int i=5; i<10; i++){
        ptr[i] = i * 1; //inicializando os novos valores
    }
    for(int i=0; i<10; i++){
        printf("%d\n", ptr[i]); //imprimindo todos os valores
    }

    free(ptr); //liberando a memoria alocada
    return 0;
}