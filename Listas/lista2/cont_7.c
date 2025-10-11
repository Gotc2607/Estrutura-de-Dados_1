#include <stdio.h>

int conta7(long long n) {
    // Caso base: nenhum dígito restante
    if (n == 0)
        return 0;

    // Verifica se o último dígito é 7
    int ultimo = n % 10;
    int cont = (ultimo == 7) ? 1 : 0;

    // Chamada recursiva para o restante do número
    return cont + conta7(n / 10);
}

int main() {
    long long n;
    scanf("%lld", &n);
    printf("%d\n", conta7(n));
    return 0;
}
