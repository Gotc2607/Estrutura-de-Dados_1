#include <stdio.h>
#include <string.h>


#define MAX 10005

int main() {
    char linha[MAX];

   
    while (scanf("%s", linha) != EOF) {
        int pilha[MAX];
        int topo = -1; 
        int caixas_validas = 0;


        for (int i = 0; linha[i] != '\0'; i++) {
            char c = linha[i];

            if (c == '[') {
              
                pilha[++topo] = 0;
            } 
            else if (c == ']') {
               
                if (topo > -1) {
                    int estado_caixa_atual = pilha[topo--]; 

                    if (estado_caixa_atual == 0) {
                        
                        caixas_validas++;
                    } else {
                        
                        if (topo > -1) {
                            pilha[topo] = 1; 
                        }
                    }
                }
            } 
            else if (c == 'x') {
                
                if (topo > -1) {
                    pilha[topo] = 1;
                }
            }
        
        }

        printf("%d\n", caixas_validas);
    }

    return 0;
}