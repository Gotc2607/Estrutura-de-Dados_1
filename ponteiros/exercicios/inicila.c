#include <stdio.h>

void dobra(int *p){

    *p = *p * 2;
}


int main(){

    int x = 10;
    int *p = &x;

    printf("%d\n", x);
    printf("%p\n", &x);
    printf("%p\n", p);
    printf("%d\n", *p);

    *p = 20; //modificando o valor de x através do ponteiro p
    printf("%d\n", x);

    dobra(&x); //passando o endereço de x para a função
    printf("%d\n", x);



    return 0;
}