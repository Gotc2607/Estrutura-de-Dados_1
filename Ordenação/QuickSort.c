#include <stdio.h>

void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particiona(int *v, int inicio, int fim){
    //escolhemos o pivor
    int pivo = v[fim];
    
    // indice para os elementos menores que o pivor
    int menores = inicio - 1;

    for(int j = inicio; j < fim; j++){

        if(v[j] < pivo){
            menores++;
            troca(&v[j], &v[menores]); // caso seja menor que o pivor esse termo vai para a esquerda do pivor
        }

    }

    troca(&v[menores + 1], &v[fim]); // coloca o pivo na posição correta com om menores a esquesrda e os maiores a direita

    return (menores + 1); // retorna o indice da posição correta do pivo


}

void Quirk_Sort(int *v, int inicio, int fim){
    if(inicio< fim){

        int indicePivo = particiona(v, inicio, fim);
        Quirk_Sort(v, inicio, indicePivo -1);
        Quirk_Sort(v, indicePivo + 1, fim);

    }

}

int main() {
    int numeros[] = {10, 80, 30, 90, 40, 50, 70};
    int n = 7;

    printf("Array original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    // CHAVE: A primeira chamada deve ser com 0 e n-1
    Quirk_Sort(numeros, 0, n - 1);

    printf("Array ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}