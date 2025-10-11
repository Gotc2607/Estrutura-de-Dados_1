#include <stdio.h>
#include <stdbool.h> // Para usar o tipo 'bool' (true/false)

/**
 * @brief Verifica se um caractere é uma vogal maiúscula.
 * @param c O caractere a ser verificado.
 * @return Retorna 'true' se for uma vogal, 'false' caso contrário.
 */
bool ehVogal(char c) {
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return true;
    }
    return false;
}

/**
 * @brief Conta recursivamente o número de vogais em uma string.
 * @param str A string a ser analisada.
 * @return O número total de vogais na string.
 */
int contarVogais(const char *str) {
    // Caso Base: Se a string está vazia (chegamos ao caractere nulo '\0'),
    // não há vogais a serem contadas. Retornamos 0.
    if (*str == '\0') {
        return 0;
    }

    // Passo Recursivo:
    // 1. Pede a um "amigo" para contar as vogais no resto da string (str + 1).
    int contagemDoResto = contarVogais(str + 1);

    // 2. Verifica se o caractere ATUAL (*str) é uma vogal.
    if (ehVogal(*str)) {
        // Se for, o total é 1 (pelo caractere atual) + o que o amigo contou.
        return 1 + contagemDoResto;
    } else {
        // Se não for, o total é 0 (pelo caractere atual) + o que o amigo contou.
        return contagemDoResto;
    }
}

int main() {
    // Declara um array de char para a entrada.
    // Tamanho 101 para acomodar os 100 caracteres mais o terminador nulo '\0'.
    char palavra[101];

    // Lê a palavra da entrada padrão.
    // scanf("%s", ...) é adequado aqui, pois a entrada não contém espaços.
    if (scanf("%s", palavra) == 1) {
        
        // Chama a função recursiva para iniciar a contagem.
        int totalVogais = contarVogais(palavra);

        // Imprime o resultado final.
        printf("%d\n", totalVogais);
    }

    return 0;
}