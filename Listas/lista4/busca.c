#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Busca iterativa
celula *busca(celula *le, int x) {
    celula *atual = le;
    while (atual != NULL) {
        if (atual->dado == x)
            return atual; // encontrou
        atual = atual->prox;
    }
    return NULL; // não encontrou
}

// Busca recursiva
celula *busca_rec(celula *le, int x) {
    if (le == NULL)
        return NULL; // caso base: fim da lista
    if (le->dado == x)
        return le; // encontrado
    return busca_rec(le->prox, x); // busca no próximo nó
}
