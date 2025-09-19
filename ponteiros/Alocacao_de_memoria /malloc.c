#include <stdio.h> 
#include <stdlib.h>

int main(){

    // malloc aloca memória na heap (memória dinâmica)
    // A memória alocada por malloc não é inicializada (pode conter lixo)
    // A memória alocada por malloc deve ser liberada com free quando não for mais necessária
    // malloc retorna um ponteiro do tipo void* que deve ser convertido para o tipo desejado
    // sizeof retorna o tamanho em bytes do tipo de dado informad

    int x = 10;
    int *p = (int*) malloc(sizeof(int)); //alocando espaço para um inteiro
    
    *p = 42; //atribuindo valor ao inteiro alocado


    
    int y = 0;
    scanf("%d", &y);
    int *ptr = (int*) malloc(y * sizeof(int)); //alocando espaço para y inteiros


    for(int i=1; i<y; i++){
        ptr[i] = i * 10; //inicializando os valores
        printf("%d\n", ptr[i]); //imprimindo os valores
    }

    //liberando a memoria alocada
    free(p);
    free(ptr);

    return 0;
}