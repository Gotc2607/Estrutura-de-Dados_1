#include <stdio.h>

int main() {
    char local[100000], aeroporto[100000];
    scanf("%s", local);
    scanf("%s", aeroporto);

    // calcula o tamanho do aeroporto e ignora o 'x' ou 'X' final
    int len = 0;
    while(aeroporto[len] != '\0') len++;
    if(len > 0 && (aeroporto[len - 1] == 'x' || aeroporto[len - 1] == 'X')) len--;

    int i = 0, j = 0; // i -> aeroporto, j -> local

    while(i < len && local[j] != '\0') {
        char a = aeroporto[i];
        char l = local[j];

        if(a >= 'A' && a <= 'Z') a += 32;
        if(l >= 'A' && l <= 'Z') l += 32;

        if(a == l) i++; // se bate, passa para o próximo caractere do aeroporto
        j++; // sempre avança no local
    }

    printf(i == len ? "Sim\n" : "Nao\n");

    return 0;
}
