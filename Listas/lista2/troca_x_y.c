#include <stdio.h>
#include <string.h>

void troca(char *str){
    if(*str == '\0'){
        return;
    }
    if(*str == 'x'){
        *str = 'y';
    }

    troca(str + 1);

}

int main(){

    char str[81];
    scanf("%s", str);

    troca(str);
    printf("%s\n", str);


    return 0;
}