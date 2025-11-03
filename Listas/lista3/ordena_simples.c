#include <stdio.h>

int main() {
    int v[1000];
    int n = 0;

    // Lê todos os números até o EOF
    while (scanf("%d", &v[n]) != EOF) {
        n++;
    }

    // Algoritmo de Ordenação por Seleção (Selection Sort)
    for (int i = 0; i < n - 1; i++) {
        int indice_min = i;

        // Encontra o menor elemento no restante do vetor
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[indice_min]) {
                indice_min = j;
            }
        }

        // Troca o menor encontrado com o elemento da posição i
        if (indice_min != i) {
            int temp = v[i];
            v[i] = v[indice_min];
            v[indice_min] = temp;
        }
    }

    // Imprime o vetor ordenado sem espaço no final
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", v[i]);
    }
    printf("\n");

    return 0;
}
