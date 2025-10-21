#include <stdio.h>
#include <string.h>

void semX(char *s){
    if(*s == '\0'){
        return;
    }
    if(*s != 'x'){
        printf("%c", *s);
    }
    semX(s+1);
}

void moveX(char *s){
    if(*s == '\0'){
        return;
    }
    if(*s == 'x'){
        printf("%c", *s);
    }
    moveX(s+1);
}

int main(){
    char s[101] = {0};
    scanf("%s", s);
    semX(s);
    moveX(s);
    printf("\n");
    return 0;
}