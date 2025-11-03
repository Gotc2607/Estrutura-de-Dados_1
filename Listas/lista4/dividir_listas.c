#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void divide_lista(celula *l, celula *l1, celula *l2) {
    celula *atual = l->prox; // primeiro elemento da lista original
    celula *fim1 = l1;       // último nó da lista de ímpares
    celula *fim2 = l2;       // último nó da lista de pares

    while (atual != NULL) {
        celula *proximo = atual->prox; // guarda próximo antes de alterar ponteiros

        if (atual->dado % 2 != 0) { // ímpar
            fim1->prox = atual;
            fim1 = atual;
        } else { // par
            fim2->prox = atual;
            fim2 = atual;
        }

        atual = proximo;
    }

    // termina as listas
    fim1->prox = NULL;
    fim2->prox = NULL;
}
