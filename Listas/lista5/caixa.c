#include <stdio.h>
#include <string.h>

// Definimos um tamanho máximo seguro para a entrada e a pilha
#define MAX 10005

int main() {
    char linha[MAX];

    // O loop continua enquanto houver entrada (até o EOF)
    while (scanf("%s", linha) != EOF) {
        int pilha[MAX];
        int topo = -1; // -1 indica que a pilha está vazia
        int caixas_validas = 0;

        // Percorre cada caractere da linha
        for (int i = 0; linha[i] != '\0'; i++) {
            char c = linha[i];

            if (c == '[') {
                // Abre uma nova caixa: empilha 0 (assumindo que é boa)
                pilha[++topo] = 0;
            } 
            else if (c == ']') {
                // Fecha a caixa atual
                if (topo > -1) {
                    int estado_caixa_atual = pilha[topo--]; // Remove da pilha

                    if (estado_caixa_atual == 0) {
                        // Se a caixa não foi marcada como ruim, ela conta!
                        caixas_validas++;
                    } else {
                        // Se a caixa atual é ruim (1), ela estraga a caixa pai
                        if (topo > -1) {
                            pilha[topo] = 1; // Marca o pai como ruim
                        }
                    }
                }
            } 
            else if (c == 'x') {
                // Encontrou produto danificado: marca a caixa atual (topo) como ruim (1)
                if (topo > -1) {
                    pilha[topo] = 1;
                }
            }
            // O caractere '.' é ignorado pois não altera o estado
        }

        printf("%d\n", caixas_validas);
    }

    return 0;
}