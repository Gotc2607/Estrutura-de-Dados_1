#include <stdio.h>
#include <string.h> // Necessário para a função strcspn

/**
 * @brief Imprime recursivamente uma string ao contrário.
 * @param str Um ponteiro para o início da string a ser impressa.
 */
void imprimeAoContrario(const char *str) {
    // Caso Base: Se o caractere atual for o terminador nulo ('\0'),
    // significa que chegamos ao fim da string. A função simplesmente retorna.
    if (*str == '\0') {
        return;
    }

    // Passo Recursivo:
    // 1. Chama a função para o restante da string (a partir do próximo caractere).
    imprimeAoContrario(str + 1);

    // 2. Após o retorno da chamada recursiva, imprime o caractere atual.
    putchar(*str);
}

int main() {
    // Declara um buffer para armazenar a string de entrada.
    // Tamanho 502 para 500 caracteres, 1 para o '\n' e 1 para o '\0'.
    char entrada[502];

    // Lê uma linha inteira da entrada padrão de forma segura com fgets.
    // fgets é mais seguro que scanf porque limita o número de caracteres lidos.
    if (fgets(entrada, sizeof(entrada), stdin) != NULL) {
        
        // fgets lê também a quebra de linha ('\n') no final. Vamos removê-la.
        // strcspn encontra o índice da primeira quebra de linha.
        // Trocamos esse caractere por um terminador nulo.
        entrada[strcspn(entrada, "\n")] = '\0';
        
        // Chama a função recursiva para imprimir a string ao contrário.
        imprimeAoContrario(entrada);

        // Imprime um caractere de nova linha no final da saída.
        printf("\n");
    }

    return 0;
}