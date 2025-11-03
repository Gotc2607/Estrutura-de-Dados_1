#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void mescla_listas(celula *l1, celula *l2, celula *l3) {
    celula *p1 = l1->prox; // primeiro elemento de l1
    celula *p2 = l2->prox; // primeiro elemento de l2
    celula *atual = l3;    // ponteiro para construir l3

    while (p1 != NULL && p2 != NULL) {
        if (p1->dado <= p2->dado) {
            atual->prox = p1;
            p1 = p1->prox;
        } else {
            atual->prox = p2;
            p2 = p2->prox;
        }
        atual = atual->prox;
    }

    // Anexa o restante de l1 ou l2
    if (p1 != NULL)
        atual->prox = p1;
    else
        atual->prox = p2;
}
