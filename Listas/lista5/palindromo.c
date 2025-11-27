#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char palavra[1000]; 
    
    
    scanf("%d", &n);
    
    
    getchar(); 
    fgets(palavra, n + 2, stdin); 
    
   
    int len = strlen(palavra);
    if (len > 0 && palavra[len - 1] == '\n') {
        palavra[len - 1] = '\0';
    }
    
    int ehPalindromo = 1; 
    
    
    for (int i = 0; i < n / 2; i++) {
        if (palavra[i] != palavra[n - 1 - i]) {
            ehPalindromo = 0;
            break;
        }
    }
    
  
    printf("%d\n", ehPalindromo);
    
    return 0;
}