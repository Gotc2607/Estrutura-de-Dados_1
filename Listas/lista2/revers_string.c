#include <stdio.h>

/**
 * @brief Imprime recursivamente uma string ao contrário.
 * * @param str Um ponteiro para o início da string a ser impressa.
 */
void imprimeAoContrario(char *str) {
    // Caso Base: Se o caractere atual for o terminador nulo ('\0'),
    // significa que chegamos ao fim da string. A função simplesmente retorna.
    if (*str == '\0') {
        return;
    }

    // Passo Recursivo:
    // 1. Chama a função para o restante da string (a partir do próximo caractere).
    imprimeAoContrario(str + 1);

    // 2. Após o retorno da chamada recursiva (ou seja, quando o restante
    // da string já foi impresso ao contrário), imprime o caractere atual.
    putchar(*str);
}

int main() {
    // Declara um array de char para armazenar a string de entrada.
    // Tamanho 501 para acomodar os 500 caracteres mais o terminador nulo '\0'.
    char entrada[501];

    // Lê a string da entrada padrão.
    // A função scanf com "%s" lê até o primeiro espaço em branco.
    if (scanf("%s", entrada) == 1) {
        
        // Chama a função recursiva para imprimir a string ao contrário.
        imprimeAoContrario(entrada);

        // Imprime um caractere de nova linha no final, para corresponder
        // ao formato de saída dos exemplos.
        printf("\n");
    }

    return 0;
}