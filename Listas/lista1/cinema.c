#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int F, L;
    scanf("%d %d", &F, &L);
    char sala[F][L];

    for(int i = 0; i < F; i++) {
        for(int j = 0; j < L; j++) {
            sala[i][j]='0'; // Inicializa 0 como livre
        }
    }
    char cadeira[4];
    while(scanf("%s", cadeira) != EOF) {
        int fileira = cadeira[0] - 'A';
        int coluna = atoi(cadeira + 1) - 1;
        sala[fileira][coluna] = '1'; // Marca como ocupada
    }
    printf("  ");
    for(int i = 1; i <= L; i++) {
        printf(" %02d", i);
    }
    printf("\n");
    for(int i = F - 1; i >= 0; i--) {
        printf("%c ", 'A' + i);
        for(int j = 0; j < L; j++) {
            printf("%s ", sala[i][j] == '1' ? "XX" : "--");
        }
        printf("\n");
    }
    return 0;
}
