#include <stdio.h>

#define REGIOES 8
#define MAX 100000
#define MAX_TOTAL (REGIOES * MAX)

// Função para intercalar dois vetores ordenados
int intercala2(int a[], int na, int b[], int nb, int r[]) {
    int i = 0, j = 0, k = 0;

    // Enquanto houver elementos em ambos
    while (i < na && j < nb) {
        if (a[i] <= b[j])
            r[k++] = a[i++];
        else
            r[k++] = b[j++];
    }

    // Copia o restante (se sobrou em a)
    while (i < na)
        r[k++] = a[i++];

    // Copia o restante (se sobrou em b)
    while (j < nb)
        r[k++] = b[j++];

    return k; // Retorna o tamanho do vetor resultante
}

int main() {
    int S[REGIOES];
    int dados[REGIOES][MAX];
    int n_resultado = 0;
    int resultado[MAX_TOTAL]; // vetor final com tudo intercalado

    // Leitura dos 8 vetores
    for (int i = 0; i < REGIOES; i++) {
        if (scanf("%d", &S[i]) != 1) S[i] = 0; // caso entrada acabe
        for (int j = 0; j < S[i]; j++) {
            scanf("%d", &dados[i][j]);
        }
    }

    // Inicializa resultado com o primeiro vetor
    for (int i = 0; i < S[0]; i++) {
        resultado[i] = dados[0][i];
    }
    n_resultado = S[0];

    // Intercala gradualmente os demais vetores
    for (int i = 1; i < REGIOES; i++) {
        int temporario[MAX_TOTAL];
        n_resultado = intercala2(resultado, n_resultado, dados[i], S[i], temporario);

        // Copia o resultado temporário de volta
        for (int j = 0; j < n_resultado; j++) {
            resultado[j] = temporario[j];
        }
    }

    // Imprime o vetor final
    for (int i = 0; i < n_resultado; i++) {
        if (i > 0) printf(" ");
        printf("%d", resultado[i]);
    }
    printf("\n");

    return 0;
}
