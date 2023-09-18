#ifndef PILHADINAMICA_H_INCLUDED
#define PILHADINAMICA_H_INCLUDED

struct aluno{
    int matricula;
    char nome[50];
    float av1;
    float av2;
    float pr;
};


typedef struct elemento Elemento;
typedef struct pilha Pilha;

Pilha* criar();

int vazia(Pilha *pd);

int cheia(Pilha *pd);

int tamanho(Pilha *pd);



int inserir(Pilha *pd, struct aluno dados);

int remover(Pilha *pd);

int acessar(Pilha *pd, struct aluno *a);

void destruir(Pilha *pd);

int imprimePilha(Pilha *pd);


#endif // PILHADINAMICA_H_INCLUDED
