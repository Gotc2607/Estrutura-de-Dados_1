#include <stdio.h>

int busca_binaria(int v[], int n, int x) {
    int ini = 0, fim = n - 1, meio;
    int resposta = n; // se x > todos, j = n

    while (ini <= fim) {
        meio = (ini + fim) / 2;
        if (x <= v[meio]) {
            resposta = meio;
            fim = meio - 1;
        } else {
            ini = meio + 1;
        }
    }

    return resposta;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int v[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);
        int j = busca_binaria(v, N, x);
        printf("%d\n", j);
    }

    return 0;
}
