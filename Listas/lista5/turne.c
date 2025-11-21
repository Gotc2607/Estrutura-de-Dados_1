#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CIDADE 27

typedef struct celula {
    char cidade[MAX_CIDADE];
    struct celula *prox;
} celula;

typedef struct {
    celula *inicio;
    celula *fim;
} Fila;

void inicializar_fila(Fila *f) {
    f->inicio = f->fim = NULL;
}

void enfileirar(Fila *f, char cidade[]) {
    celula *novo = malloc(sizeof(celula));
    strcpy(novo->cidade, cidade);
    novo->prox = NULL;
    
    if (f->fim == NULL) {
        f->inicio = f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int fila_vazia(Fila *f) {
    return f->inicio == NULL;
}

void desenfileirar(Fila *f, char cidade[]) {
    if (fila_vazia(f)) return;
    
    celula *temp = f->inicio;
    strcpy(cidade, temp->cidade);
    f->inicio = f->inicio->prox;
    
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    
    free(temp);
}

char ultima_letra(char cidade[]) {
    int len = strlen(cidade);
    return tolower(cidade[len - 1]);
}

char primeira_letra(char cidade[]) {
    return tolower(cidade[0]);
}

int main() {
    Fila fila;
    inicializar_fila(&fila);
    char cidade[MAX_CIDADE];
    
    // Lê todas as cidades e enfileira
    while (scanf("%s", cidade) != EOF) {
        enfileirar(&fila, cidade);
    }
    
    if (fila_vazia(&fila)) {
        return 0;
    }
    
    // Processa o primeiro show (sempre na primeira cidade)
    char cidade_atual[MAX_CIDADE];
    desenfileirar(&fila, cidade_atual);
    printf("%s\n", cidade_atual);
    
    char ultima_letra_show = ultima_letra(cidade_atual);
    
    // Processa o restante dos shows
    while (!fila_vazia(&fila)) {
        char proxima_cidade[MAX_CIDADE];
        desenfileirar(&fila, proxima_cidade);
        
        // Se a próxima cidade começa com a mesma letra que terminou o último show
        if (primeira_letra(proxima_cidade) == ultima_letra_show) {
            // Vai para o final da fila
            enfileirar(&fila, proxima_cidade);
        } else {
            // Faz o show nesta cidade
            printf("%s\n", proxima_cidade);
            ultima_letra_show = ultima_letra(proxima_cidade);
        }
    }
    
    return 0;
}