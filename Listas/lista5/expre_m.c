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
        return 0; 
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
        
  
        if (caractere == '(' || caractere == '[' || caractere == '{') {
            empilhar(&pilha, caractere);
        }
  
        else if (caractere == ')' || caractere == ']' || caractere == '}') {
        
            if (estaVazia(&pilha)) {
                return 0;
            }
            
            char topo_pilha = desempilhar(&pilha);
            
        
            if (!corresponde(topo_pilha, caractere)) {
                return 0;
            }
        }
    }
   
    return estaVazia(&pilha);
}

int main() {
    char expressao[MAX + 1];
    
    
    fgets(expressao, sizeof(expressao), stdin);
    
   
    int len = strlen(expressao);
    if (len > 0 && expressao[len - 1] == '\n') {
        expressao[len - 1] = '\0';
    }
    
  
    if (verificarParentizacao(expressao)) {
        printf("sim\n");
    } else {
        printf("nao\n");
    }
    
    return 0;
}