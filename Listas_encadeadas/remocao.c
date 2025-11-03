#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Remove o elemento imediatamente depois de p
void remove_depois(celula *p) {
    if (p == NULL || p->prox == NULL)
        return; // não há elemento para remover

    celula *temp = p->prox;
    p->prox = temp->prox;
    free(temp);
}

// Remove a primeira ocorrência de x na lista
void remove_elemento(celula *le, int x) {
    if (le == NULL)
        return;

    celula *atual = le;

    // percorre até achar o nó anterior ao que tem dado = x
    while (atual->prox != NULL && atual->prox->dado != x) {
        atual = atual->prox;
    }

    // se encontrou, remove
    if (atual->prox != NULL) {
        remove_depois(atual);
    }
}

// Remove todas as ocorrências de x na lista
void remove_todos_elementos(celula *le, int x) {
    if (le == NULL)
        return;

    celula *atual = le;

    // percorre toda a lista, removendo nós com dado = x
    while (atual->prox != NULL) {
        if (atual->prox->dado == x) {
            remove_depois(atual);
        } else {
            atual = atual->prox;
        }
    }
}
