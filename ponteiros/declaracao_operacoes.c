#include <stdio.h>

int main() {

    int x = 10;

    int *ptr = &x; // Declarando um ponteiro que aponta para x

    printf("%d\n", x);      // Imprime o valor de x
    printf("%d\n", *ptr);   // Imprime o valor apontado por ptr
    printf("%p\n", (void*)&x);   // Imprime o endereço de x
    printf("%p\n", (void*)ptr);  // Imprime o valor do ponteiro (endereço de x)
    printf("%p\n", (void*)&ptr); // Imprime o endereço do ponteiro ptr

    // & significa endereço de memória

    return 0;
}