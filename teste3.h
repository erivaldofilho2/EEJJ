typedef struct no {

    int prioridade;
    struct arvore *arvore;
    struct no *proximoNo;

}No;

typedef struct fila {

    No *inicio;

}FilaPrioridade;

typedef struct arvore {

    char caractere;
    struct arvore *direita;
    struct arvore *esquerda;

}Arvore;

Arvore* CriaArvoreBinaria(char caractere);

FilaPrioridade* insereNoFila(FilaPrioridade *fila,int frequencia,char caractere);

FilaPrioridade* RemoveNoFilaPrioridade(FilaPrioridade *fila);

FilaPrioridade* CriaFilaPrioridade();

int eFolha( Arvore *arvore );
