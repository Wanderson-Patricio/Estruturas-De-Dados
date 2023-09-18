#include <stdlib.h>
#include <stdio.h>
#include "filaEstatica.h"

struct fila{
    int qtd, inicio, fim;
    struct aluno dados[MAX];
};

Fila* criar(){
    Fila *fe;
    fe = (Fila*) malloc(sizeof(Fila));
    if(fe != NULL){
        fe->qtd = 0;
        fe->inicio = 0;
        fe->fim = 0;
    }
    return fe;
}



void destruir(Fila *fe){
    free(fe);
}

int tamanho(Fila *fe){
    if(fe == NULL){
        return -1;
    }else{
        return fe->qtd;
    }
}

int cheia(Fila *fe){
    if(fe == NULL){
        return -1;
    }else if(fe->qtd == MAX){
        return 1;
    }else{
        return 0;
    }
}

int vazia(Fila *fe){
    if(fe == NULL){
        return -1;
    }else if(fe->qtd == 0){
        return 1;
    }else{
        return 0;
    }
}

int inserir(Fila *fe, struct aluno novo){
    if(fe == NULL){
        return 0;
    }else if(cheia(fe)){
        return 0;
    }else{
        fe->dados[fe->fim] = novo;
        fe->qtd++;
        fe->fim = (fe->fim +1)%MAX;
        return 1;
    }
}

int remover(Fila *fe){
    if(fe == NULL){
        return 0;
    }else if(vazia(fe)){
        return 0;
    }else{
        fe->inicio = (fe->inicio+1)%MAX;
        fe->qtd--;
        return 1;
    }
}

int acessar(Fila *fe, struct aluno *a){
    if(fe == NULL){
        return 0;
    }else if(vazia(fe)){
        return 0;
    }else{
        *a = fe->dados[fe->inicio];
        return 1;
    }
}

int imprimeFila(Fila *fe){
    if(fe == NULL){
        return 0;
    }else{
        for(int i = fe->inicio; i < fe->fim; i++){
            printf("--------------------------------\n");
            printf("Nome: %s\nMatricula: %d\n", fe->dados[i].nome, fe->dados[i].matricula);
            printf("--------------------------------\n");
        }
        return 1;
    }
}
