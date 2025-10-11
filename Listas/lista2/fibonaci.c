#include <stdio.h>

long int fibonacci(int n) {
    static long int memo[81] = {0}; // Armazena os resultados de 1 até 80

    // Caso base
    if (n == 1 || n == 2)
        return 1;

    // Se o valor já foi calculado, retorna
    if (memo[n] != 0)
        return memo[n];

    // Calcula e armazena
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}
