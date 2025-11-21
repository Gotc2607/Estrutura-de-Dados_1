#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 100
#define MAX_STACK 1000

typedef struct {
    char dados[MAX_STACK][MAX_STR + 1];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

int empilhar(Pilha *p, char *str) {
    if (p->topo == MAX_STACK - 1) {
        return 0; // Pilha cheia
    }
    strcpy(p->dados[++(p->topo)], str);
    return 1;
}

int desempilhar(Pilha *p, char *str) {
    if (estaVazia(p)) {
        return 0; // Pilha vazia
    }
    strcpy(str, p->dados[(p->topo)--]);
    return 1;
}

int main() {
    Pilha pilha;
    inicializar(&pilha);
    char comando[10];
    char str[MAX_STR + 1];
    char resultado[MAX_STR + 1];
    
    while (scanf("%s", comando) != EOF) {
        if (strcmp(comando, "inserir") == 0) {
            // Lê a string até o final da linha
            getchar(); // Consome o espaço após "inserir"
            fgets(str, sizeof(str), stdin);
            
            // Remove o caractere de nova linha se existir
            int len = strlen(str);
            if (len > 0 && str[len - 1] == '\n') {
                str[len - 1] = '\0';
            }
            
            empilhar(&pilha, str);
        }
        else if (strcmp(comando, "desfazer") == 0) {
            if (desempilhar(&pilha, resultado)) {
                printf("%s\n", resultado);
            } else {
                printf("NULL\n");
            }
        }
    }
    
    return 0;
}