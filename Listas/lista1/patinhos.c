#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int P,PFinal, M = 0, N = 0;
    int linhaInicio, colunaInicio;
    char caminho[1000], mapa[1000][1000];
    scanf("%d", &P);
    PFinal = P;
    while(scanf("%s", caminho) != EOF){   
        N = strlen(caminho);//colunas 
        for(int j = 0; j < N; j++){
            mapa[M][j] = caminho[j];
        }
        M++;
    }
    for(int k = 0; k < M; k++){
        for(int l = 0; l < N; l++){
            // printf("%c", mapa[k][l]);
            if(mapa[k][l] == 'S'){
                linhaInicio = k;
                colunaInicio = l;
            }
        }
        // printf("\n");
    }
    int linhaAtual = linhaInicio;
    int colunaAtual = colunaInicio;
    while(mapa[linhaAtual][colunaAtual] != 'E'){
        if(mapa[linhaAtual+1][colunaAtual] != '#' && linhaAtual+1 < M){
            if(mapa[linhaAtual+1][colunaAtual] == 'o') PFinal--;
            if(P < 0) break;
            mapa[linhaAtual][colunaAtual] = '#';
            linhaAtual++;
        } else if(mapa[linhaAtual][colunaAtual+1] != '#' && colunaAtual+1 < N){
            if(mapa[linhaAtual][colunaAtual+1] == 'o') PFinal--;
            if(P < 0) break;
            mapa[linhaAtual][colunaAtual] = '#';
            colunaAtual++;
        } else if(mapa[linhaAtual-1][colunaAtual] != '#' && linhaAtual-1 >= 0){
            if(mapa[linhaAtual-1][colunaAtual] == 'o') PFinal--;
            if(P < 0) break;
            mapa[linhaAtual][colunaAtual] = '#';
            linhaAtual--;
        } else if(mapa[linhaAtual][colunaAtual-1] != '#' && colunaAtual-1 >= 0){
            if(mapa[linhaAtual][colunaAtual-1] == 'o') PFinal--;
            if(P < 0) break;
            mapa[linhaAtual][colunaAtual] = '#';
            colunaAtual--;
        }
    }
    // printf("PFinal: %d\n", PFinal);
    if(PFinal <= 0) printf("Todos morreram :)");
    else if(PFinal == P) printf("Nenhum morreu :(");
    else printf("%d encontraram o vovo", PFinal);
        // printf("(%d,%d)\n", linhaAtual, colunaAtual);
        // printf("%d\n", P);
    return 0;
}