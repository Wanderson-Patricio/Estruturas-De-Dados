#ifndef FILAESTATICA_H_INCLUDED
#define FILAESTATICA_H_INCLUDED

#define MAX 50

struct aluno{
    int matricula;
    char nome[50];
    float av1;
    float av2;
    float pr;
};

typedef struct fila Fila;

Fila* criar();



void destruir(Fila *fe);

int tamanho(Fila *fe);

int cheia(Fila *fe);

int vazia(Fila *fe);

int inserir(Fila *fe, struct aluno novo);

int remover(Fila *fe);

int acessar(Fila *fe, struct aluno *a);

int imprimeFila(Fila *fe);

#endif // FILAESTATICA_H_INCLUDED
