#include <stdio.h>

int main() {
    char local[100];
    char aeroporto[100];

    scanf("%s", local);
    scanf("%s", aeroporto);

    int found = 1;
    int pos = 0;

    // calcula o tamanho de aeroporto
    int len = 0;
    while(aeroporto[len] != '\0') len++;

    // se terminar em 'x', ignora o último caractere
    if(len > 0 && aeroporto[len - 1] == 'x' || len > 0 && aeroporto[len - 1] == 'X') len--;

    for(int i = 0; i < len; i++) {
        int match = 0;
        while(local[pos] != '\0') {
            char a = aeroporto[i];
            char l = local[pos];

            if(a >= 'A' && a <= 'Z') a += 32;
            if(l >= 'A' && l <= 'Z') l += 32;

            if(a == l) {
                match = 1;
                pos++;
                break;
            }
            pos++;
        }
        if(!match) {
            found = 0;
            break;
        }
    }

    if(found) {
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }

    return 0;
}
