#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *enfileira(celula *f, int x) {
    celula *novo = malloc(sizeof(celula));
    if (novo == NULL) return NULL;
    
    novo->dado = x;
    if (f == NULL) {
        novo->prox = novo; 
        return novo;
    }
    
    celula *atual = f;
    
    while (atual->prox != f) {
        atual = atual->prox;
    }
    
    atual->prox = novo; 
    novo->prox = f;     
    
    return f; 
}