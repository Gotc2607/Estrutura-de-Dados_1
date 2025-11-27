#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;


typedef struct {
    celula *inicio;
    celula *fim;
} FilaWrapper;

celula *enfileira(celula *f, int x) {
    static FilaWrapper wrapper = {NULL, NULL};
    
   
    if (f != NULL && wrapper.inicio == NULL) {
        wrapper.inicio = f;
        celula *atual = f;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        wrapper.fim = atual;
    }
    
   
    celula *novo = malloc(sizeof(celula));
    if (novo == NULL) return NULL;
    
    novo->dado = x;
    novo->prox = NULL;
   
    if (wrapper.inicio == NULL) {
        wrapper.inicio = wrapper.fim = novo;
        return novo;
    }
    
    
    wrapper.fim->prox = novo;
    wrapper.fim = novo;
    
    return wrapper.inicio;
}