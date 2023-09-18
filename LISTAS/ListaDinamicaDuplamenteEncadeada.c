#include <stdlib.h>
#include <stdio.h>
#include "listaDinamicaDuplamenteEncadeada.h"

struct elemento{
    struct elemento *anterior;
    struct aluno dados;
    struct elemento *proximo;
};

typedef struct elemento Elemento;

Lista* criar(){
    Lista *ldde;
    ldde = (Lista *)malloc(sizeof(Lista));
    if(ldde != NULL){
        *ldde = NULL;
    }
    return ldde;
}

void destruir(Lista *ldde){
    if(ldde != NULL){
        Elemento *aux;
        while(*ldde != NULL){
            aux = *ldde;
            *ldde = (*ldde)->proximo;
            free(aux);
        }
    }
}


int tamanho(Lista *ldde){
    if(ldde == NULL){
        return -1;
    }else if(vazia(ldde)){
        return 0;
    }else{
        int cont = 0;
        Elemento *aux = *ldde;
        while(aux != NULL){
            aux = aux->proximo;
            cont++;
        }
        return cont;
    }
}

int cheia(Lista *ldde){
    return 0;
}

int vazia(Lista *ldde){
    if(ldde == NULL){
        return 1;
    }else if(*ldde == NULL){
        return 1;
    }else{
        return 0;
    }
}

int inserirInicio(Lista* ldde, struct aluno dados){
    if(ldde == NULL){
        return 0;
    }else{
        Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
        if(novo == NULL){
            return 0;
        }else{
            novo->anterior = NULL;
            novo->dados = dados;
            novo->proximo = *ldde;
            if(*ldde != NULL){
                (*ldde)->anterior = novo;
            }
            *ldde = novo;
            return 1;
        }
    }
}

int inserirFim(Lista* ldde, struct aluno dados){
    if(ldde == NULL){
        return 0;
    }else{
        Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
        novo->dados = dados;
        novo->proximo = NULL;
        if(vazia(ldde)){
            novo->anterior = NULL;
            *ldde = novo;
        }else{
            Elemento *aux = *ldde;
            while(aux->proximo != NULL){
                aux = aux->proximo;
            }
            aux->proximo = novo;
            novo->anterior = aux;
        }
        return 1;
    }
}

int inserirOrdenado(Lista* ldde, struct aluno dados){
    if(ldde == NULL){
        return 0;
    }else{
        Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
        novo->dados = dados;
        if(vazia(ldde) || (*ldde)->dados.matricula > dados.matricula){
            novo->anterior = NULL;
            novo->proximo = *ldde;
            if(*ldde != NULL){
                (*ldde)->anterior = novo;
            }
            *ldde = novo;
            return 1;
        }else{
            Elemento *ant = *ldde;
            Elemento *aux = ant->proximo;
            while(aux != NULL && aux->dados.matricula < dados.matricula){
                ant = aux;
                aux = aux->proximo;
            }
            ant->proximo = novo;
            if(aux != NULL){
                aux->anterior = novo;
            }
            novo->anterior = ant;
            novo->proximo = aux;
            return 1;
        }
    }
}

int removerInicio(Lista* ldde){
    if(vazia(ldde)){
        return 0;
    }else{
        Elemento *aux = *ldde;
        *ldde = aux->proximo;
        if(aux->proximo != NULL){
            aux->proximo->anterior = NULL;
        }
        free(aux);
        return 1;
    }
}

int removerFim(Lista* ldde){
    if(vazia(ldde)){
        return 0;
    }else if((*ldde)->proximo == NULL){
        Elemento *aux = *ldde;
        *ldde = aux->proximo;
        free(aux);
        return 1;
    }else{
        Elemento *aux = *ldde;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->anterior->proximo = NULL;
        free(aux);
        return 1;
    }
}

int removerValor(Lista* ldde, int x){
    if(vazia(ldde)){
        return 0;
    }else if((*ldde)->dados.matricula == x){
        Elemento *aux = *ldde;
        *ldde = aux->proximo;
        free(aux);
        return 1;
    }else{
        Elemento *aux = *ldde;
        while(aux != NULL && aux->dados.matricula != x){
            aux = aux->proximo;
        }
        //nao achou o elemento
        if(aux == NULL){
            return 0;
        }else{
            aux->anterior->proximo = aux->proximo;
            if(aux->proximo != NULL){
                aux->proximo->anterior = aux->anterior;
            }
            free(aux);
            return 1;
        }
    }
}


int acessarIndice(Lista *ldde, int pos, struct aluno *a){
    if(vazia(ldde) || pos < 0){
        return 0;
    }else{
        int cont = 0;
        Elemento *aux = *ldde;
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

int acessarValor(Lista *ldde, int x, struct aluno *dados){
    if(vazia(ldde)){
        return 0;
    }else{
        Elemento *aux = *ldde;
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


int imprimeLista(Lista *ldde){
    if(ldde == NULL){
        return 0;
    }else{
        Elemento *aux = *ldde;
        while(aux != NULL){
            printf("--------------------------------\n");
            printf("Nome: %s\nMatricula: %d\n", aux->dados.nome, aux->dados.matricula);
            printf("--------------------------------\n");
            aux = aux->proximo;
        }
        return 1;
    }
}
