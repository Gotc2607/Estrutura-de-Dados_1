// 1 - é escolhodo uma chave que é comparada com os outros termos do array
// 2 - se a chave for menor que o termo atual esse termo é movido para a direita
// 3 - 

#include <stdio.h>

void Insertion_Sort(int *v, int n){
    for(int i = 1; i<n; i++){ //como asssumimos que o primeiro elemento está ordenado começamos pelo segundo elemento v[1]
        int chave = v[i]; // armazenamos o valor no indice i atual 

        int j = i - 1; // definimos j como o indice logo a esquerda do i 

        while(j >= 0 && v[j] > chave){ // enquanto j for maior ou igual a 0 e o valor no indice j for maior que a chave
            v[j+1] = v[j]; // movemos o valor para a direita
            j--; // diminuimos j para agora verificarmos o proximo numero a esquerda
        }
        v[j+1] = chave; // inserimos a chave na posição correta
    }
}

int main(){

    int v[] = {7 ,1 , 4, 3, 2, 8};
    int n = sizeof(v)/sizeof(v[0]); // calcula  o tamanho do vetor usando sizeof

    Insertion_Sort(v, n);

    for(int i =0; i < n; i++){
        printf("%d ", v[i]);
    }


    return 0;
}