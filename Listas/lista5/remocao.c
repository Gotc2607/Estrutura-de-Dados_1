#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int desenfileira(fila *f, int *y) {
    // Verifica se a fila está vazia
    if (f->p == f->u) {
        return 0; // Fila vazia, remoção mal sucedida
    }
    
    // Remove o elemento do início da fila e salva em y
    *y = f->dados[f->p];
    
    // Atualiza o ponteiro p (início) considerando fila circular
    f->p = (f->p + 1) % f->N;
    
    return 1; // Remoção bem sucedida
}