#include <stdio.h>

int main(){

    int n = 0;
    scanf("%d", &n);

    for(int i=1; i<n+1; i++){
       for(int j=1; j<i+1; j++){
        printf("%02d ", i);
       }
       printf("\n");
    }

    printf("\n");

    for(int i=1; i<n+1; i++){
       for(int j=1; j<i+1; j++){
        printf("%02d ", j);
       }
       printf("\n");
    }

    return 0;
}