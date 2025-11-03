#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Insere no início da lista (após o nó cabeça)
void insere_inicio(celula *le, int x) {
    celula *novo = (celula *)malloc(sizeof(celula));
    if (!novo) return; // erro de alocação
    novo->dado = x;
    novo->prox = le->prox;
    le->prox = novo;
}

// Insere antes da primeira ocorrência de y
// Se y não existir, insere no final
void insere_antes(celula *le, int x, int y) {
    celula *atual = le;
    
    // percorre enquanto próximo não for NULL e próximo->dado != y
    while (atual->prox != NULL && atual->prox->dado != y) {
        atual = atual->prox;
    }
    
    // cria o novo nó
    celula *novo = (celula *)malloc(sizeof(celula));
    if (!novo) return; // erro de alocação
    novo->dado = x;
    
    // insere antes do nó com dado y (ou no final se y não existe)
    novo->prox = atual->prox;
    atual->prox = novo;
}
