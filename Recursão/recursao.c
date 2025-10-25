// recursão é quando uma função chama ela mesma
// o caso base é usado como condição de parada 

#include <stdio.h>

// Exemplo 1: Soma de n elementos até 1

int soma(int n){
    //usa-se o caso base como condição
    if(n == 1){
        return 1;
    }
    else{
        return n + soma(n-1); // soma n com a soma dos numeros menores que ela até o numero 1 
    }
}

//Exemplo 2: fatorial

int fatorial(int n){
    if(n == 0){
        return 1;
    }
    else{
        return n * fatorial(n-1);
    }
}

int main(){

    int n = 5;

    int fa = fatorial(n);
    printf("fatorial de 5 : %d\n", fa);

    int su = soma(n);
    printf("Soma : %d\n", su);

    return 0;
}