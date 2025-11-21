#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Estrutura para manter o início e fim da fila
typedef struct {
    celula *inicio;
    celula *fim;
} FilaWrapper;

celula *enfileira(celula *f, int x) {
    static FilaWrapper wrapper = {NULL, NULL};
    
    // Se é a primeira chamada, inicializa o wrapper
    if (f != NULL && wrapper.inicio == NULL) {
        wrapper.inicio = f;
        // Encontra o fim atual da fila
        celula *atual = f;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        wrapper.fim = atual;
    }
    
    // Cria novo nó
    celula *novo = malloc(sizeof(celula));
    if (novo == NULL) return NULL;
    
    novo->dado = x;
    novo->prox = NULL;
    
    // Se a fila está vazia
    if (wrapper.inicio == NULL) {
        wrapper.inicio = wrapper.fim = novo;
        return novo;
    }
    
    // Insere no final (O(1) usando o ponteiro para o fim)
    wrapper.fim->prox = novo;
    wrapper.fim = novo;
    
    return wrapper.inicio;
}