#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 8

typedef struct {
    int x, y, dist;
} Posicao;

int movimentos[8][2] = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

int dentroDoTabuleiro(int x, int y) {
    return x >= 0 && x < TAM && y >= 0 && y < TAM;
}

int bfs(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) return 0;
    
    int visitado[TAM][TAM] = {0};
    Posicao fila[TAM * TAM];
    int inicio = 0, fim = 0;
    
   
    fila[fim].x = x1;
    fila[fim].y = y1;
    fila[fim].dist = 0;
    fim++;
    visitado[x1][y1] = 1;
    
    while (inicio < fim) {
        Posicao atual = fila[inicio];
        inicio++;
        
       
        for (int i = 0; i < 8; i++) {
            int novoX = atual.x + movimentos[i][0];
            int novoY = atual.y + movimentos[i][1];
            
            if (dentroDoTabuleiro(novoX, novoY) && !visitado[novoX][novoY]) {
                
                if (novoX == x2 && novoY == y2) {
                    return atual.dist + 1;
                }
                
                
                fila[fim].x = novoX;
                fila[fim].y = novoY;
                fila[fim].dist = atual.dist + 1;
                fim++;
                visitado[novoX][novoY] = 1;
            }
        }
    }
    
    return -1; 
}

int main() {
    char origem[3], destino[3];
    
    while (scanf("%s %s", origem, destino) != EOF) {
        
        int x1 = origem[0] - 'a';
        int y1 = origem[1] - '1';
        int x2 = destino[0] - 'a';
        int y2 = destino[1] - '1';
        
        int movimentos = bfs(x1, y1, x2, y2);
        
        printf("To get from %s to %s takes %d knight moves.\n", 
               origem, destino, movimentos);
    }
    
    return 0;
}