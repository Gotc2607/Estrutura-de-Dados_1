#include <stdio.h>


//ponteiros permitem passar endereços de variáveis para funções
 void funcao(int *p){
    *p = *p * 2; //dobrando o valor da variável apontada por p
 }

 int soma(int a, int b){
    return a + b;
 }

int main(){

    int x,y = 0;
    scanf("%d", &x);
    scanf("%d", &y);

    int resultado = soma(x,y); //chamando a função soma

    printf("Antes da funcao: %d\n", resultado);

    funcao(&resultado); //passando o endereço de x para a função

    printf("Depois da funcao: %d\n", resultado); //x agora é 20

    return 0;
}