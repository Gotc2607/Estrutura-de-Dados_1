#include <stdio.h>

void troca(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;

}

int main(){

    int x = 10;
    int y = 20;

    int *p1 = &x; //ponteiro p1 aponta para x
    int *p2 = &y; //ponteiro p2 aponta para y

    printf("valor x: %d\n", x);
    printf("valor y: %d\n", y);

    troca(&x, &y); //passando os endereços de x e y para a função troca
    printf("Troca realizada\n");

    printf("valor x: %d\n", x);
    printf("valor y: %d\n", y);


    return 0;
}