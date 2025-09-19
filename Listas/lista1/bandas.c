#include <stdio.h>
#include <string.h>

// Estrutura para armazenar informações de uma banda
struct tipoBanda {
    char nome[80];
    int ano;
};

// Estrutura para armazenar informações de um show
struct tipoShow {
    char nome[80];
    int qtd; // quantidade de bandas no show
    struct tipoBanda bandas[100];
};

// Função que pesquisa uma banda nos shows
void pesquisarNomeBanda(char pesquisa[80], struct tipoShow shows[50], int n) {
    int encontrada = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < shows[i].qtd; j++) {
            if(strcmp(pesquisa, shows[i].bandas[j].nome) == 0) {
                printf("%s : ano %d\n", shows[i].nome, shows[i].bandas[j].ano);
                encontrada = 1;
            }
        }
    }

    if(!encontrada) {
        printf("Banda nao cadastrada\n");
    }
}
