#ifndef PILHAESTATICA_H_INCLUDED
#define PILHAESTATICA_H_INCLUDED

#define MAX 50

struct aluno{
    int matricula;
    char nome[50];
    float av1;
    float av2;
    float pr;
};

typedef struct pilha Pilha;

//retorna ponteiro para a Pilha ou NULL se alocacao nao for bem sucedida
Pilha* criar();
void destruir(Pilha *);
int tamanho(Pilha *);
int cheia(Pilha *);
int vazia(Pilha *);
int inserir(Pilha *, struct aluno);
int remover(Pilha *);
int acessar(Pilha *, struct aluno*);
int imprimePilha(Pilha *);


#endif // PILHAESTATICA_H_INCLUDED
