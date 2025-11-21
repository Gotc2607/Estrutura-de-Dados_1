#include <stdio.h>
#include <string.h>

#define MAX 500

typedef struct {
    char itens[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

int empilhar(Pilha *p, char elemento) {
    if (p->topo == MAX - 1) {
        return 0; // Pilha cheia
    }
    p->itens[++(p->topo)] = elemento;
    return 1;
}

char desempilhar(Pilha *p) {
    if (estaVazia(p)) {
        return '\0';
    }
    return p->itens[(p->topo)--];
}

char topo(Pilha *p) {
    if (estaVazia(p)) {
        return '\0';
    }
    return p->itens[p->topo];
}

int corresponde(char abertura, char fechamento) {
    return (abertura == '(' && fechamento == ')') ||
           (abertura == '[' && fechamento == ']') ||
           (abertura == '{' && fechamento == '}');
}

int verificarParentizacao(char *expressao) {
    Pilha pilha;
    inicializar(&pilha);
    
    int tamanho = strlen(expressao);
    
    for (int i = 0; i < tamanho; i++) {
        char caractere = expressao[i];
        
        // Se for um caractere de abertura, empilha
        if (caractere == '(' || caractere == '[' || caractere == '{') {
            empilhar(&pilha, caractere);
        }
        // Se for um caractere de fechamento, verifica correspondência
        else if (caractere == ')' || caractere == ']' || caractere == '}') {
            // Se a pilha estiver vazia, há um fechamento sem abertura correspondente
            if (estaVazia(&pilha)) {
                return 0;
            }
            
            char topo_pilha = desempilhar(&pilha);
            
            // Verifica se o fechamento corresponde à abertura
            if (!corresponde(topo_pilha, caractere)) {
                return 0;
            }
        }
    }
    
    // Se a pilha estiver vazia no final, todos os parênteses/colchetes/chaves foram fechados corretamente
    return estaVazia(&pilha);
}

int main() {
    char expressao[MAX + 1];
    
    // Lê a expressão matemática
    fgets(expressao, sizeof(expressao), stdin);
    
    // Remove o caractere de nova linha se existir
    int len = strlen(expressao);
    if (len > 0 && expressao[len - 1] == '\n') {
        expressao[len - 1] = '\0';
    }
    
    // Verifica se a expressão está corretamente parentizada
    if (verificarParentizacao(expressao)) {
        printf("sim\n");
    } else {
        printf("nao\n");
    }
    
    return 0;
}