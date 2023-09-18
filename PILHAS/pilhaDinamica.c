#include <stdlib.h>
#include <stdio.h>
#include "pilhaDinamica.h"

typedef struct elemento{
    struct aluno dados;
    struct elemento *proximo;
}Elemento;


Pilha* criar(){
    Pilha *pd;
    pd = (Pilha*) malloc(sizeof(Pilha));
    if(pd != NULL){
        *pd = NULL;
    }
    return pd;
}

int vazia(Pilha *pd){
    if(pd == NULL){
        return 1;
    }else if(*pd == NULL){
        return 1;
    }else{
        return 0;
    }
}

int cheia(Pilha *pd){
    return 0;
}

int tamanho(Pilha *pd){
    if(pd == NULL){
        return 0;
    }else if(vazia(pd)){
        return 0;
    }else{
        int cont = 0;
        Elemento *aux = *pd;
        while(aux != NULL){
            cont++;
            aux = aux->proximo;
        }
        return cont;
    }
}



int inserir(Pilha *pd, struct aluno dados){
    if (pd == NULL){
        return 0;
    }else{
        Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
        if(novo == NULL){
            return 0;
        }else{
            novo->dados = dados;
            novo->proximo = *pd;
            *pd = novo;
            return 1;
        }
    }
}

int remover(Pilha *pd){
    if(vazia(pd)){
        return 0;
    }else{
        Elemento *aux = *pd;
        *pd = aux->proximo;
        free(aux);
        return 1;
    }
}

int acessar(Pilha *pd, struct aluno *a){
    if(vazia(pd)){
        return 0;
    }else{
        *a = (*pd)->dados;
        return 1;
    }
}

void destruir(Pilha *pd){
    if(pd != NULL){
        Elemento *aux;
        while(*pd != NULL){
            aux = *pd;
            *pd = (*pd)->proximo;
            free(aux);
        }
        free(pd);
    }
}

int imprimePilha(Pilha *pd){
    if(pd == NULL){
        return 0;
    }else{
        Elemento *aux = *pd;
        while(aux != NULL){
            printf("--------------------------------\n");
            printf("Nome: %s\nMatricula: %d\n", aux->dados.nome, aux->dados.matricula);
            printf("--------------------------------\n");
            aux = aux->proximo;
        }
        return 1;
    }
}
