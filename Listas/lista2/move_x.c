#include <stdio.h>
#include <string.h>

void move_x(char *s, char *resultado) {
    // Caso base: string vazia
    if (*s == '\0') {
        *resultado = '\0';
        return;
    }

    // Processa o primeiro caractere
    char primeiro = *s;

    // Chama recursivamente para o restante da string
    move_x(s + 1, resultado);

    // Se o caractere for 'x', adiciona no final
    if (primeiro == 'x') {
        int len = strlen(resultado);
        resultado[len] = 'x';
        resultado[len + 1] = '\0';
    }
    // Caso contrário, adiciona no início
    else {
        int len = strlen(resultado);
        // Desloca tudo uma posição à frente
        memmove(resultado + 1, resultado, len + 1);
        resultado[0] = primeiro;
    }
}

int main() {
    char entrada[101], saida[101] = "";
    scanf("%100s", entrada);

    move_x(entrada, saida);
    printf("%s\n", saida);

    return 0;
}
