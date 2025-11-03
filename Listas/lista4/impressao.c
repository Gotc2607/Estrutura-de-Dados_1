#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Impressão iterativa
void imprime(celula *le) {
    celula *atual = le->prox; 

    if (atual == NULL) {
       
        printf("NULL");
     
    } else {
        
        while (atual != NULL) {
            printf("%d", atual->dado);
            if (atual->prox != NULL)
                printf(" -> ");
            atual = atual->prox;
        }
        printf(" -> NULL");
    }
    
    
    printf("\n");
}

// Função auxiliar (helper) que faz a recursão
void imprime_rec_helper(celula *no) {
    
    if (no->prox == NULL) {
        printf("%d -> NULL", no->dado);
        return;
    }


    printf("%d -> ", no->dado);
    imprime_rec_helper(no->prox);
}

// Função principal
void imprime_rec(celula *le) {
    celula *primeiro_no_real = le->prox;

    if (primeiro_no_real == NULL) {
    
        printf("NULL");
    } else {
        
        imprime_rec_helper(primeiro_no_real);
    }

    
    printf("\n");
}