#include <stdlib.h>
#include <stdio.h>
#include "ListaSequencialEstatica.h"

struct lista {
    int qtd;
    struct aluno dados[MAX];
};

Lista * criar(){
    Lista * lse;
    lse = (Lista *)malloc(sizeof(Lista));
    if(lse != NULL){
        lse->qtd = 0;
    }
    return lse;
}

void destruir(Lista *lse){
    free(lse);
}

int tamanho(Lista *lse){
    if(lse == NULL){
        return -1;
    }else{
        return lse->qtd;
    }
}

int cheia(Lista *lse){
    if(lse == NULL){
        return -1;
    }else if(lse->qtd == MAX){
        return 1;
    }else{
        return 0;
    }
}

int vazia(Lista * lse){
    if(lse == NULL){
        return -1;
    }else if(lse->qtd == 0){
        return 1;
    }else{
        return 0;
    }
}

int inserirFim(Lista *lse, struct aluno novo){
    if(lse == NULL){
        return 0;
    }else if(cheia(lse)){
        return 0;
    }else{
        lse->dados[lse->qtd] = novo;
        lse->qtd++;
        return 1;
    }
}

int inserirInicio(Lista* lse, struct aluno novo){
    if(lse == NULL){
        return 0;
    }else if(cheia(lse)){
        return 0;
    }else{
        //deslocar elementos para a direita
        int i;
        for(i = (lse->qtd) - 1; i>= 0; i--){
            lse->dados[i+1] = lse->dados[i];
        }
        //insere no inicio
        lse->dados[0] = novo;
        lse->qtd++;
        return 1;
    }
}

int inserirOrdenado(Lista * lse, struct aluno novo){
        if(lse == NULL){
        return 0;
    }else if(cheia(lse)){
        return 0;
    }else{
        int i, pos = 0;
        //procura indice
        while(lse->dados[pos].matricula < novo.matricula && pos < lse->qtd){
            pos++;
        }
        //desloca restante dos elementos para a direita
        for(i = (lse->qtd) - 1; i >=pos; i--){
            lse->dados[i+1] = lse->dados[i];
        }
        //insiro no indice correto
        lse->dados[pos] = novo;
        lse->qtd++;
        return 1;
    }
}

int removerFim(Lista *lse){
    if(lse == NULL){
        return 0;
    }else if(vazia(lse)){
        return 0;
    }else{
        lse->qtd--;
        return 1;
    }
}

int removerInicio(Lista *lse){
    if(lse == NULL){
        return 0;
    }else if(vazia(lse)){
        return 0;
    }else{
        int i;
        for(i = 0; i <= (lse->qtd) -1; i++){
            lse->dados[i] = lse->dados[i+1];
        }
        lse->qtd--;
        return 1;
    }
}

int removerValor(Lista *lse, int matricula){

    if(lse == NULL){
        return 0;
    }else if(vazia(lse)){
        return 0;
    }else{
        //procura valor
        int i, pos = 0;
        while(lse->dados[pos].matricula != matricula && pos < lse->qtd){
            pos++;
        }
        //elemento nao existe
        if(pos == lse->qtd){
            return 0;
        }
        //deslocar elementos para a esquerda
        for(i = pos; i <= (lse->qtd) - 1; i++){
            lse->dados[i] = lse->dados[i+1];
        }
        lse->qtd--;
        return 1;
    }

}

int acessarIndice(Lista *lse, int pos, struct aluno *a){
    if(lse == NULL){
        return 0;
    }else if (pos < 0 || pos >= lse->qtd){
        return 0;
    }else{
        *a = lse->dados[pos];
        return 1;
    }
}

int acessarValor(Lista *lse, int mat, struct aluno *a){
    if(lse == NULL){
        return 0;
    }else{
        int pos = 0;
        while(lse->dados[pos].matricula != mat && pos < lse->qtd){
            pos++;
        }
        if(pos == lse->qtd){
            return 0;
        }
        *a = lse->dados[pos];
        return 1;
    }
}


void imprimeLista(Lista *lse){
    if(lse == NULL){
        printf("Lista nao inicializada\n");
    }else if(vazia(lse)){
        printf("Lista vazia.\n");
    } else{
        int i;
        for(i = 0; i < lse->qtd; i++){
            printf("Nome: %s;\nMatricula:%d;\n", lse->dados[i].nome, lse->dados[i].matricula);
        }
    }
}
