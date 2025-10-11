#include <stdio.h>

// Função auxiliar para desenhar uma linha com n traços
void desenhaLinha(int n) {
    // Imprime o ponto inicial
    printf(".");
    // Imprime 'n' traços
    for (int i = 0; i < n; i++) {
        printf("-");
    }
    // Imprime a quebra de linha
    printf("\n");
}

// Função recursiva para desenhar a régua inglesa
void desenhaRegua(int n) {
    // Caso base: Se n for 0 ou menor, a função retorna e a recursão para.
    if (n <= 0) {
        return;
    }

    // 1. Chamada recursiva para desenhar a régua superior de ordem n-1
    desenhaRegua(n - 1);

    // 2. Desenha o traço central (o maior) para a ordem n atual
    desenhaLinha(n);

    // 3. Chamada recursiva para desenhar a régua inferior de ordem n-1
    desenhaRegua(n - 1);
}

int main() {
    int n;

    // Lê o inteiro não negativo da entrada padrão
    if (scanf("%d", &n) == 1) {
        // Chama a função principal para iniciar o desenho
        desenhaRegua(n);
    }

    return 0;
}