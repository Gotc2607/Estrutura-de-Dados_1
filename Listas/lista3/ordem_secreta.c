#include <stdio.h>
#include <stdlib.h>


int compara(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return (x - y);
}


int busca_binaria(int v[], int n, int chave) {
    int ini = 0, fim = n - 1;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        if (v[meio] == chave)
            return meio;
        else if (v[meio] < chave)
            ini = meio + 1;
        else
            fim = meio - 1;
    }
    return -1; 
}

int main() {
    int N, C;
    scanf("%d %d", &N, &C);

    int original[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &original[i]);
    }

    
    int ordenado[N];
    for (int i = 0; i < N; i++) {
        ordenado[i] = original[i];
    }

    qsort(ordenado, N, sizeof(int), compara);

    int indice = busca_binaria(ordenado, N, C);

    
    printf("%d\n", indice);

    for (int i = 0; i < N; i++) {
        int j = (i + indice) % N;
        printf("%d", original[j]);
        if (i < N - 1) printf(" ");
    }
    printf("\n");

    return 0;
}
