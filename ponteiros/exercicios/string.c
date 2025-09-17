#include <stdio.h>
#include <string.h>

void n_vogais(char *str, int *n){
    *n = 0; //inicializando n com 0
    for(int i=0; str[i] != EOF; i++){ //percorrendo a string até o caractere nulo
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
           str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
            (*n)++; //incrementando n se encontrar uma vogal
        }
    }
}

int main(){

    int n = 0;

    char str[100]; //declarando um array de caracteres (string) com tamanho 100
    printf("Digite uma string: ");
    scanf("%99s", str); //lendo a string (máximo 99 caracteres + '\0')
    printf("\n");
    n_vogais(str, &n); //passando a string e o endereço de n para a função
    printf("Número de vogais: %d\n", n); //imprimindo o número de vogais

    
    return 0;
}