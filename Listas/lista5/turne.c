#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct Node {
    char nome[30];
    struct Node *proximo;
} Node;


Node *inicio = NULL;
Node *fim = NULL;


void enfileirar(char *cidade) {
    Node *novo = (Node*) malloc(sizeof(Node));
    strcpy(novo->nome, cidade);
    novo->proximo = NULL;

    if (inicio == NULL) {
        inicio = novo;
        fim = novo;
    } else {
        fim->proximo = novo;
        fim = novo;
    }
}


Node* desenfileirar() {
    if (inicio == NULL) return NULL;

    Node *temp = inicio;
    inicio = inicio->proximo;

    if (inicio == NULL) {
        fim = NULL;
    }
    return temp;
}


void mover_primeiro_para_final() {
    if (inicio == NULL || inicio == fim) return; 

    
    fim->proximo = inicio;
    fim = inicio;
    
    
    inicio = inicio->proximo;
    
    
    fim->proximo = NULL;
}

int main() {
    char buffer[30];

    
    while (scanf("%s", buffer) != EOF) {
        enfileirar(buffer);
    }

    
    if (inicio == NULL) return 0;


    Node *atual = desenfileirar();
    printf("%s\n", atual->nome);

    
    int tamanho = strlen(atual->nome);
    char ultima_letra = atual->nome[tamanho - 1];
    
    free(atual); 

    
    while (inicio != NULL) {
        
        char primeira_letra_prox = tolower(inicio->nome[0]);

        if (primeira_letra_prox == ultima_letra) {
            mover_primeiro_para_final();
        }

        
        atual = desenfileirar();
        printf("%s\n", atual->nome);

        tamanho = strlen(atual->nome);
        ultima_letra = atual->nome[tamanho - 1];

        free(atual);
    }

    return 0;
}