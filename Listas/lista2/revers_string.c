#include <stdio.h>

void imprime_invertido(char *s) {
    if (*s == '\0')  // caso base
        return;

    imprime_invertido(s + 1);  // chamada recursiva
    putchar(*s);               // imprime o caractere após voltar da recursão
}

int main() {
    char str[501];
    scanf("%500s", str);

    imprime_invertido(str);
    putchar('\n');

    return 0;
}
