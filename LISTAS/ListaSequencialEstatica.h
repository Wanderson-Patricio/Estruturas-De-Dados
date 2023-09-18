#ifndef LISTASEQUENCIALESTATICA_H_INCLUDED
#define LISTASEQUENCIALESTATICA_H_INCLUDED

#define MAX 50

struct aluno {
    int matricula;
    char nome[50];
    float av1;
    float av2;
    float pr;
};

typedef struct lista Lista;

Lista* criar();
void destruir(Lista *);
int tamanho(Lista *);
int cheia(Lista *);
int vazia(Lista *);
int inserirFim (Lista *, struct aluno);
int inserirInicio (Lista * lse , struct aluno);
int inserirOrdenado (Lista *, struct aluno);
int removerFim (Lista *);
int removerInicio (Lista *);
int removerValor (Lista *, int);
int acessarIndice (Lista *, int , struct aluno *);
int acessarValor (Lista *, int , struct aluno *);
void imprimeLista(Lista *);

#endif // LISTASEQUENCIALESTATICA_H_INCLUDED
