#include <stdlib.h>
#include <stdio.h>
#include "pilhaEstatica.h"

struct pilha{
    int qtd;
    struct aluno dados[MAX];
};

Pilha* criar(){
    Pilha *pe;
    pe = (Pilha*) malloc(sizeof(Pilha));
    if(pe != NULL){
        pe->qtd = 0;
    }
    return pe;
}

void destruir(Pilha *pe){
    free(pe);
}

int tamanho(Pilha *pe){
    if(pe == NULL){
        return -1;
    }
    return pe->qtd;
}

int cheia(Pilha *pe){
    if(pe == NULL){
        return -1;
    }else if(pe->qtd == MAX){
        return 1;
    }else{
        return 0;
    }
}

int vazia(Pilha *pe){
    if(pe == NULL){
        return -1;
    }else if(pe->qtd == 0){
        return 1;
    }else{
        return 0;
    }
}

int inserir(Pilha *pe, struct aluno novo){
    if(pe == NULL){
        return 0;
    }else if(cheia(pe)){
        return 0;
    }else{
        pe->dados[pe->qtd] = novo;
        pe->qtd++;
        return 1;
    }
}

int remover(Pilha *pe){
    if(pe == NULL){
        return 0;
    }else if(vazia(pe)){
        return 0;
    }else{
        pe->qtd--;
        return 1;
    }
}

int acessar(Pilha *pe, struct aluno *a){
    if(pe == NULL){
        return 0;
    }else if(vazia(pe)){
        return 0;
    }else{
        *a = pe->dados[pe->qtd-1];
        return 1;
    }
}

int imprimePilha(Pilha *pe){
    if(pe == NULL){
        return 0;
    }else{
        for(int i = (pe->qtd - 1); i >= 0; i--){
            printf("--------------------------------\n");
            printf("Nome: %s\nMatricula: %d\n", pe->dados[i].nome, pe->dados[i].matricula);
            printf("--------------------------------\n");
        }
        return 1;
    }
}
