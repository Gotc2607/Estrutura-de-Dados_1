#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int busca_binaria(int *v, int n, int x){
    int inicio = 0;
    int fim = n-1;
    while(inicio<=fim){
        int meio = (inicio+fim)/2;

        if(v[meio]==x){
            return meio;
        }
        else if(v[meio]<x){
            inicio = meio+1;
        }
        else{
            fim = meio-1;
        }
    }
    return -1;
}

int particiona(int *v, int inicio, int fim){
    int pivo = v[fim];
    int menor = inicio;

    for(int k = inicio; k<fim; k++){
        if(v[k]<pivo){
            troca(&v[menor], &v[k]);
            menor++;
        }
    }
    troca(&v[menor], &v[fim]);
    return menor;
}

void quicksort(int *v, int inicio, int fim){
    if(inicio<fim){
        int indicepivo = particiona(v, inicio, fim);
        quicksort(v, inicio, indicepivo-1);
        quicksort(v, indicepivo+1, fim);
    }
}


int main() {
    int N;
    if (scanf("%d", &N) != 1)
        return 0;

    int *proibidos = (int *)malloc(N * sizeof(int));
    if (!proibidos)
        return 1; // erro de alocação

    // Lê os N números proibidos
    for (int i = 0; i < N; i++) {
        scanf("%d", &proibidos[i]);
    }

    // Ordena o vetor para permitir busca binária
    quicksort(proibidos, 0, N-1);

    int consulta;
    // Lê até o EOF
    while (scanf("%d", &consulta) == 1) {
        int resultado = busca_binaria(proibidos, N, consulta);
        if (resultado != -1)
            printf("sim\n");
        else
            printf("nao\n");
    }

    free(proibidos);
    return 0;
}
