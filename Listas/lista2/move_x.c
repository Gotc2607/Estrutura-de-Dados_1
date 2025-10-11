#include <stdio.h>

// Função recursiva que move todos os 'x' para o final
void move_x(char *s, char *saida, int *pos_normal, int *pos_x) {
    if (*s == '\0') {
        saida[*pos_normal + *pos_x] = '\0';
        return;
    }

    if (*s == 'x') {
        // Guarda o 'x' mais ao fim da string de saída
        saida[*pos_normal + *pos_x] = 'x';
        (*pos_x)++;
    } else {
        // Guarda os outros caracteres na frente
        saida[*pos_normal] = *s;
        (*pos_normal)++;
    }

    move_x(s + 1, saida, pos_normal, pos_x);
}

int main() {
    char entrada[101], saida[101];
    int pos_normal = 0, pos_x = 0;

    scanf("%100s", entrada);

    move_x(entrada, saida, &pos_normal, &pos_x);

    printf("%s\n", saida);

    return 0;
}
