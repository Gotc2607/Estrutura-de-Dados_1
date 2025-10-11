#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int pares(char *s){
    int formouPares = 0;
    if(strlen(s) < 3){
        return 0;
    }else if(*s == *(s+2)){
        formouPares = 1 ;
    }
    return formouPares + pares(s+1);
}
int main(){
    char s[201];
    scanf("%s", s);
    printf("%d\n", pares(s));
    return 0;
}