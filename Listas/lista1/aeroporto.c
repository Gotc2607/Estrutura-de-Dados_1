#include <stdio.h>

int main() {
    char local[100], aeroporto[100];
    int pos = 0, found = 1;

    scanf("%s", local);
    scanf("%s", aeroporto);

    // calcula o tamanho de aeroporto
    int len;
    for(len = 0; aeroporto[len] != '\0'; len++);

    // ignora último caractere se for 'x' ou 'X'
    if(len > 0 && (aeroporto[len - 1] == 'x' || aeroporto[len - 1] == 'X')) len--;

    for(int i = 0; i < len; i++) {
        int match = 0;
        for(; local[pos] != '\0'; pos++) {
            char a = aeroporto[i];
            char l = local[pos];

            // converte para minúscula
            if(a >= 'A' && a <= 'Z') a += 32;
            if(l >= 'A' && l <= 'Z') l += 32;

            if(a == l) { match = 1; pos++; break; }
        }
        if(!match) { found = 0; break; }
    }

    printf(found ? "Sim\n" : "Nao\n");
    return 0;
}
