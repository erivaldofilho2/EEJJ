#include <stdio.h>
#include <stdlib.h>


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

//cria arvore binaria apontando pra NULL tanto a esquerda quanto a direita
Arvore* CriaArvoreBinaria(char caractere){

        Arvore *arvore = (Arvore*) malloc(sizeof(Arvore));

        arvore->caractere = caractere;
        arvore->esquerda = NULL;
        arvore->direita = NULL;

        return arvore;
}


//função insere novo nó obedecendo a prioridade.
FilaPrioridade* insereNoFila(FilaPrioridade *fila,int frequencia,char caractere){

    No *no = (No*) malloc(sizeof(No));

    no->prioridade = frequencia;

    no->arvore = CriaArvoreBinaria(caractere);

    if( (fila->inicio->proximoNo == NULL) || (frequencia < fila->inicio->prioridade )){
    printf("teste ok\n");
        no->proximoNo = fila->inicio;
        fila->inicio = no;

    }
    else{

    No *temp = fila->inicio;
    while((temp->proximoNo != NULL) && (temp->proximoNo->prioridade < frequencia)){

        temp = temp->proximoNo;
    }
    no->proximoNo = temp->proximoNo;
    temp->proximoNo = no;

    }
return fila;

}
//Remove da fila

FilaPrioridade* RemoveNoFilaPrioridade(FilaPrioridade *fila){





}
//função cria fila
FilaPrioridade* CriaFilaPrioridade(){

    FilaPrioridade *fila = malloc( sizeof(FilaPrioridade) );
    fila->inicio = malloc( sizeof( No ) );

    return fila;

}

int eFolha( Arvore *arvore )
{
    if( ( arvore->esquerda == NULL ) && ( arvore->direita == NULL ) )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*

main(){


FilaPrioridade *filaTal;

printf("Inicio de programa\n");


filaTal = CriaFilaPrioridade();
printf("Fila Tal criada!\n");

filaTal = insereNoFila(filaTal,6,'F'); printf("elemento do incio = %c ",filaTal->inicio->arvore->caractere );
filaTal = insereNoFila(filaTal,34,'H'); printf("elemento do incio = %c ",filaTal->inicio->arvore->caractere );
filaTal = insereNoFila(filaTal,5,'E');

printf("elemento do incio = %c ",filaTal->inicio->arvore->caractere );

}
*/
