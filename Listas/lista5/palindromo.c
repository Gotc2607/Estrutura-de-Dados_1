#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char palavra[1000]; // Tamanho suficiente para acomodar a entrada
    
    // Lê o tamanho da palavra
    scanf("%d", &n);
    
    // Lê a palavra (ignorando possíveis espaços ou quebras de linha)
    getchar(); // Consome o '\n' após o número
    fgets(palavra, n + 2, stdin); // +2 para o '\n' e '\0'
    
    // Remove o caractere de nova linha se existir
    int len = strlen(palavra);
    if (len > 0 && palavra[len - 1] == '\n') {
        palavra[len - 1] = '\0';
    }
    
    int ehPalindromo = 1; // Assume que é palíndromo inicialmente
    
    // Verifica se é palíndromo comparando caracteres simétricos
    for (int i = 0; i < n / 2; i++) {
        if (palavra[i] != palavra[n - 1 - i]) {
            ehPalindromo = 0;
            break;
        }
    }
    
    // Imprime o resultado
    printf("%d\n", ehPalindromo);
    
    return 0;
}