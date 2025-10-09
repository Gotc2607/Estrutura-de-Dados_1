#include <stdio.h>
#include <string.h>

int pares(char *str){

    if(strlen(str) < 3){
        return 0;
    }
    
    if(str[0] == str[2]){
        return 1 + pares(str+1);
    }
    else{
        return pares(str+1);
    }

}

int main(){

    char str[81];

    scanf("%s", str);

    int resultado = pares(str);
    printf("%d\n", resultado);


    return 0;
}