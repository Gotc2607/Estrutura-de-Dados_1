#include <stdio.h>

void Matrix(int linhas, int colunas, int matrix[linhas][colunas]){
    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            matrix[i][j] = i + j;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }}

int main(){

    int linhas = 5;
    int colunas = 5;
    int matrix[linhas][colunas];

    Matrix(linhas, colunas, matrix);

    int n = 11;

    for(int i=1; i<n+1; i++){
       for(int j=1; j<i+1; j++){
        printf("%02d ", i);
       }
       printf("\n");
    }

    printf("\n");

    for(int i=1; i<n+1; i++){
       for(int j=1; j<i+1; j++){
        printf("%02d ", j);
       }
       printf("\n");
    }

    return 0;
}