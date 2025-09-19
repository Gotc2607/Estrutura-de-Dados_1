#include <stdio.h>
#include <stdlib.h>
int main() {
    char nome[100], primeiroNome[100], ultimoNome[100];
    while(scanf("%[^\n]", nome) != EOF){
        for(int i = 0; nome[i]; i++) {
            if(nome[i] >= 'A' && nome[i] <= 'Z') {
                nome[i] = nome[i] + 32;
            }
        }
        for(int i = 0; nome[i] != ' '; i++) {
            primeiroNome[i] = nome[i];
            primeiroNome[i+1] = '\0';
        }
        int len = 0;
    while (nome[len]) len++; // calcula o tamanho da string

    for (int i = len - 1; i >= 0; i--) {
        if(nome[i] == ' ') {
            int j = 0;
            for(int k = i + 1; nome[k]; k++) {
                ultimoNome[j] = nome[k];
                ultimoNome[j+1] = '\0';
                j++;
            }
            break;
        }       
    } 
    printf("%s.%s@unb.br", primeiroNome, ultimoNome);
        
        
    return 0;
}
}