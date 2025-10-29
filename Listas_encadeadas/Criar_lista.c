#include <stdio.h>
#include <stdlib.h>


typedef struct celula{
    
    int dado;
    struct celula *prox;

}celula;

celula *Criar_lista(){
    celula *l = (celula *)malloc(sizeof(celula));

    if (l == NULL){
        printf("Erro ao alocar memoria");
        return 0;
    }

    l->dado = 0;
    l->prox = NULL;

    return l;
}

int adicionar_inicio(celula *l, int x){

    celula *nova = (celula *)malloc(sizeof(celula));

    if (nova == NULL){
        printf("Erro ao alocar memoria");
        return 0;
    }

    nova->dado = x;
    nova->prox = l->prox;
    l->prox = nova;

}

int adicionar_depois(celula *l, int x, int y){

    celula *atual = l;
    while(atual->prox != NULL && atual->prox->dado != y){
        atual = atual->prox;
    }

    if (atual->prox == NULL){
        //caso não encontre y adiciona no fim da lista
        
        return 0;
    }

    celula *nova = (celula *)malloc(sizeof(celula));

    if (nova == NULL){
        printf("Erro ao alocar memoria");
        return 0;
    }

    nova->dado = x;
    nova->prox = atual->prox;
    atual->prox = nova;

}


   
void print_lista(celula *l){
    celula *atual = l;
    while(atual->prox != NULL){
        printf("%d -> ", atual->prox->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}
int remover_inicio(celula *l){

    if (l->prox == NULL){
        printf("Lista vazia");
        return 0;
    }

    celula *temp = l->prox; // removendo o primeiro elemento da lista
    l->prox = temp->prox; // atualizando o ponteiro para o proximo elemento
    int dado = temp->dado;

    free(temp);
    return dado;
}



int main(){

    
    celula *l = Criar_lista();
    adicionar_inicio(l, 10);
    adicionar_inicio(l, 20);

    int sucesso = remover_inicio(l);
    if (sucesso){
        printf("Removido: %d\n", sucesso);
    }
    else{
        printf("Falha ao remover elemento\n");
    }
    
    

    print_lista(l);

    return 0;
}