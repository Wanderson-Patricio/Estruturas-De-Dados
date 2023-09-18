#ifndef LISTADINAMICASIMPLESMENTEENCADEADA_H_INCLUDED
#define LISTADINAMICASIMPLESMENTEENCADEADA_H_INCLUDED

struct aluno {
    int matricula;
    char nome[50];
    float av1;
    float av2;
    float pr;
};

typedef struct elemento* Lista;

Lista* criar();
void destruir(Lista *);
int tamanho(Lista *);
int cheia(Lista *);
int vazia(Lista *);
int inserirFim (Lista *, struct aluno);
int inserirInicio (Lista *, struct aluno);
int inserirOrdenado (Lista *, struct aluno);
int removerFim (Lista *);
int removerInicio (Lista *);
int removerValor (Lista *, int);
int acessarIndice (Lista *, int , struct aluno *);
int acessarValor (Lista *, int , struct aluno *);
int imprimeLista(Lista *);

#endif // LISTADINAMICASIMPLESMENTEENCADEADA_H_INCLUDED
