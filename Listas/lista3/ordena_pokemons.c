#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar dados de cada Pokémon
typedef struct {
    char id[5];  // 4 dígitos + '\0'
    int nivel;
    int status;
} Pokemon;

// Função de comparação para qsort
int compara(const void *a, const void *b) {
    Pokemon *p1 = (Pokemon*)a;
    Pokemon *p2 = (Pokemon*)b;

    // Primeiro: nível decrescente
    if (p1->nivel != p2->nivel)
        return p2->nivel - p1->nivel;

    // Segundo: status decrescente
    return p2->status - p1->status;
}

int main() {
    int N;
    scanf("%d", &N);

    Pokemon lista[N];

    for (int i = 0; i < N; i++) {
        scanf("%s %d %d", lista[i].id, &lista[i].nivel, &lista[i].status);
    }

    qsort(lista, N, sizeof(Pokemon), compara);

    for (int i = 0; i < N; i++) {
        printf("%s | %d | %d\n", lista[i].id, lista[i].nivel, lista[i].status);
    }

    return 0;
}
