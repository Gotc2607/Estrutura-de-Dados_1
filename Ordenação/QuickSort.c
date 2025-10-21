// Quick Sort Implementation in C

int Particiona(int *v, int inicio, int fim){
    int pivo = v[fim]; // escolhendo o pivo como o ultimo elemento
    int i = inicio - 1; // indice do menor elemento

    for(int j = inicio; j < fim; j++){ // percorrendo o vetor
        if(v[j] <= pivo){ // se o elemento atual for menor ou igual ao pivo
            i++; // incrementa o indice do menor elemento
            int temp = v[i]; // troca v[i] com v[j]
            v[i] = v[j];
            v[j] = temp;
        }
    }
    int temp = v[i + 1]; // troca v[i + 1] com v[fim] (ou pivo)
    v[i + 1] = v[fim];
    v[fim] = temp;
    return i + 1; // retorna o indice do pivo

}