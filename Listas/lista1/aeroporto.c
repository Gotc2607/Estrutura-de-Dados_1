#include <stdio.h>

int main() {
    char local[100];
    char aeroporto[100];

    scanf("%s", local);
    scanf("%s", aeroporto);

    int found = 1; // assumimos que todos os caracteres vão ser encontrados
    int pos = 0;   // posição atual em local

    for(int i = 0; aeroporto[i] != '\0'; i++) {
        int match = 0;
        while(local[pos] != '\0') {
            char a = aeroporto[i];
            char l = local[pos];

            // converte para minúscula manualmente
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

