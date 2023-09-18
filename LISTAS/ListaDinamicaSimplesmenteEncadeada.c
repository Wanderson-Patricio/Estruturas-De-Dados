#include <stdlib.h>
#include <stdio.h>
#include "listaDinamicaSimplesmenteEncadeada.h"

struct elemento{
    struct aluno dados;
    struct elemento *proximo;
};

typedef struct elemento Elemento;

Lista* criar(){
    Lista *ldse;
    ldse = (Lista *)malloc(sizeof(Lista));
    if(ldse != NULL){
        *ldse = NULL;
    }
    return ldse;
}

void destruir(Lista *ldse){
    if(ldse != NULL){
        Elemento *aux;
        while(*ldse != NULL){
            aux = *ldse;
            *ldse = (*ldse)->proximo;
            free(aux);
        }
    }
}


int tamanho(Lista *ldse){
    if(ldse == NULL){
        return -1;
    }else if(vazia(ldse)){
        return 0;
    }else{
        int cont = 0;
        Elemento *aux = *ldse;
        while(aux != NULL){
            aux = aux->proximo;
            cont++;
        }
        return cont;
    }
}

int cheia(Lista *ldse){
    return 0;
}

int vazia(Lista *ldse){
    if(ldse == NULL){
        return 1;
    }else if(*ldse == NULL){
        return 1;
    }else{
        return 0;
    }
}

int inserirInicio(Lista *ldse, struct aluno dados){

    if(ldse == NULL){
        return 0;
    }else{
        Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
        if(novo == NULL){
            return 0;
        }else{
            //1- encapsula aluno em um novo elemento
            //2- faz ponteiro do novo elemento apontas pra o inicio da lista
            //3- faz inicio da lista apontar para o novo elemento
            novo->dados = dados;
            novo->proximo = *ldse;
            *ldse = novo;
            return 1;
        }
    }
}

int inserirFim(Lista *ldse, struct aluno dados){
    if(ldse == NULL){
        return 0;
    }else{

        Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
        if(novo == NULL){
            return 0;
        }else{
            novo->dados = dados;
            novo->proximo = NULL;
            if(vazia(ldse)){
                *ldse = novo;
            }else{
                Elemento *aux = *ldse;
                while(aux->proximo != NULL){
                    aux = aux->proximo;
                }
                aux->proximo = novo;
            }
            return 1;
        }
    }
}

int inserirOrdenado(Lista *ldse, struct aluno dados){
    if(ldse == NULL){
        return 0;
    }else{
        Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
        if(novo == NULL){
            return 0;
        }else{
            novo->dados = dados;
            if(vazia(ldse) || (*ldse)->dados.matricula > novo->dados.matricula){
                *ldse = novo;
            }else{
                Elemento *ant = *ldse;
                Elemento *aux = ant->proximo;
                while(aux != NULL && aux->dados.matricula < novo->dados.matricula){
                    ant = aux;
                    aux = aux->proximo;
                }
                ant->proximo = novo;
                novo->proximo = aux;
            }
            return 1;
        }
    }
}

int removerInicio(Lista *ldse){
    if(vazia(ldse)){
        return 0;
    }else{
        Elemento *aux = *ldse;
        *ldse = aux->proximo;
        free(aux);
        return 1;
    }
}

int removerFim(Lista *ldse){

    if(vazia(ldse)){
        return 0;
    }else if((*ldse)->proximo == NULL){
        Elemento *aux = *ldse;
        *ldse = aux->proximo;
        free(aux);
        return 1;
    }else{
        Elemento *ant = *ldse;
        Elemento *aux = ant->proximo;
        while(aux->proximo != NULL){
            ant = aux;
            aux = aux->proximo;
        }
        ant->proximo = aux->proximo;
        free(aux);
        return 1;
    }
}


int removerValor(Lista *ldse, int x){
    if(vazia(ldse)){
        return 0;
    }else if((*ldse)->dados.matricula == x){
        Elemento *aux = *ldse;
        *ldse = aux->proximo;
        free(aux);
        return 1;
    }else{
        Elemento *ant = *ldse;
        Elemento *aux = ant->proximo;
        while(aux != NULL && aux->dados.matricula != x){
            ant = aux;
            aux = aux->proximo;
        }
        //chegou ao fim da lista e nao achou o elemento
        if(aux == NULL){
            return 0;
        }
        //achou o elemento
        ant->proximo = aux->proximo;
        free(aux);
        return 1;
    }
}

int acessarIndice(Lista *ldse, int pos, struct aluno *a){
    if(vazia(ldse) || pos < 0){
        return 0;
    }else{
        int cont = 0;
        Elemento *aux = *ldse;
        while(aux != NULL && pos != cont){
            aux = aux->proximo;
            cont++;
        }
        //chegou ao fim da lista e nao achou
        if(aux == NULL){
            return 0;
        }else{
            *a = aux->dados;
            return 1;
        }

    }
}

int acessarValor(Lista *ldse, int x, struct aluno *dados){
    if(vazia(ldse)){
        return 0;
    }else{
        Elemento *aux = *ldse;
        while(aux != NULL && aux->dados.matricula != x){
            aux = aux->proximo;
        }
        //chegou ao fim da lista e nao achou
        if(aux == NULL){
            return 0;
        }else{
            *dados = aux->dados;
            return 1;
        }
    }
}


int imprimeLista(Lista *ldse){
    if(ldse == NULL){
        return 0;
    }else{
        Elemento *aux = *ldse;
        while(aux != NULL){
            printf("--------------------------------\n");
            printf("Nome: %s\nMatricula: %d\n", aux->dados.nome, aux->dados.matricula);
            printf("--------------------------------\n");
            aux = aux->proximo;
        }
        return 1;
    }
}
