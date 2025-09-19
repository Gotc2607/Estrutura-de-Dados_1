#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int D, A, S, m, matriculados, aprovados;
    scanf("%d", &D);
    while(scanf("%d %d %d", &A, &S, &m) == 3){
        printf("%d/%d\n", A, S);
        int codigo[m], reprovados[m],  maior = -1;
        for(int i = 0; i < m; i++){
           scanf("%d %d %d", &codigo[i], &matriculados, &aprovados);
            reprovados[i] = matriculados - aprovados;
            if(reprovados[i]>maior)  maior = reprovados[i];
        }
        int qntMaiores = 0;
        for(int i = 0; i < m; i++)
        {
            if(reprovados[i] == maior)
            {
                qntMaiores++;
            }
        }
        int codigoMaiores[qntMaiores];
        for(int i = 0, j = 0; i < m; i++)
        {
            if(reprovados[i] == maior)
            {
                codigoMaiores[j] = codigo[i];
                j++;
            }
        }
        for(int i = 0; i < qntMaiores; i++)
        {
            for(int j = i + 1; j < qntMaiores; j++)
            {
                if(codigoMaiores[i] > codigoMaiores[j])
                {
                    int temp = codigoMaiores[i];
                    codigoMaiores[i] = codigoMaiores[j];
                    codigoMaiores[j] = temp;
                }
            }
        }
        for(int i = 0; i < qntMaiores; i++)
                printf("%d ", codigoMaiores[i]);
    
        printf("\n");
    }
    return 0;
}
