#include <stdio.h>


void copia_string(char *original, char *copia){
    for(int i=0; original[i] != EOF; i++){
        copia[i] = original[i]; //copiando cada caractere da string original para a string copia
    }
}

int main(){


    int n = 0;
    char str[100]; //declarando um array de caracteres (string) com tamanho 100
    printf("Digite uma string: ");
    scanf("%99s",str); //lendo a string (máximo 99 caracteres + '\0')
    printf("\n");   

    char copia[100]; //declarando um array de caracteres (string) para a cópia

    copia_string(str, copia); //copiando a string str para a string copia

    printf("String original: %s\n", str); //imprimindo a string original
    printf("String copiada: %s\n", copia); //imprimindo a string copiada

    return 0;
}