#include <stdio.h>

int rlen(const char *s) {
    if (*s == '\0') return 0;
    return 1 + rlen(s + 1);
}

void move_x_rec(const char *s, char *out, int *front, int *back) {
    if (*s == '\0') {
        out[*front] = '\0'; // front == number of non-'x' colocados; também é posição para '\0'
        return;
    }

    if (*s == 'x') {
        out[*back] = 'x';
        (*back)--;
    } else {
        out[*front] = *s;
        (*front)++;
    }

    move_x_rec(s + 1, out, front, back);
}

int main() {
    char entrada[101], saida[101];
    if (scanf("%100s", entrada) != 1) return 0;

    int len = rlen(entrada);
    int front = 0;
    int back = len - 1;

    move_x_rec(entrada, saida, &front, &back);

    printf("%s\n", saida);
    return 0;
}
