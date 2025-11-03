#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Função iterativa
void imprime(celula *le) {
    if (le == NULL) {
        printf("NULL");
        return;
    }

    celula *atual = le;
    while (atual != NULL) {
        printf("%d", atual->dado);
        if (atual->prox != NULL)
            printf(" -> ");
        atual = atual->prox;
    }
    printf(" -> NULL");
}

// Função recursiva
void imprime_rec(celula *le) {
    if (le == NULL) {
        printf("NULL");
        return;
    }

    printf("%d", le->dado);
    if (le->prox != NULL) {
        printf(" -> ");
        imprime_rec(le->prox);
    } else {
        printf(" -> NULL");
    }
}
