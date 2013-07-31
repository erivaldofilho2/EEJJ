#include <stdio.h>
#include <stdlib.h>
#include "teste3.h"
#define MAX_FILA_C 8192

typedef struct fila_circular{

    unsigned char valores[MAX_FILA_C];
    int tamanho;
    int primeiro;
    int ultimo;

}FilaCircular;

typedef struct lista_circular{

    unsigned char valor_bin;
    struct lista_circular *prox;
    struct lista_circular *ante;

}ListaCircular;

FilaCircular *criarFilaCircular()
{
    FilaCircular *fila_circular = malloc( sizeof( FilaCircular ) );
    fila_circular->tamanho = 0;
    fila_circular->primeiro = 0;
    fila_circular->ultimo = MAX_FILA_C - 1;
    return fila_circular;
}

ListaCircular *criarListaCircular()
{
    ListaCircular *lista_circular = malloc( sizeof(ListaCircular) );
    lista_circular->prox = lista_circular;
    lista_circular->ante = lista_circular;
    lista_circular->valor_bin = '#';
    return lista_circular;
}

int EnfileirarFilaC( FilaCircular *fila_circular , unsigned char valor )
{
    if ( fila_circular->tamanho >= MAX_FILA_C )
    {
        return 0;
    }
    else
    {
        fila_circular->ultimo = ( fila_circular->ultimo + 1 ) % MAX_FILA_C;
        fila_circular->valores[fila_circular->ultimo] = valor; //printf("%c",valor);
        fila_circular->tamanho++;
        return 1;
    }
}

ListaCircular *inserirListaCircular( ListaCircular *lista , unsigned char valor )
{
    ListaCircular *nova_lista = malloc( sizeof(ListaCircular) );
    ListaCircular *root = lista->prox;

    nova_lista->valor_bin = valor;

    root->ante = nova_lista;
    nova_lista->prox = lista->prox;
    lista->prox = nova_lista;
    nova_lista->ante = lista;
    return nova_lista;
}

int DesenfileirarFilaC( FilaCircular *fila_circular )
{
    int removido = fila_circular->primeiro;
    if( fila_circular->tamanho <= 0 )
    {
        //Log
    }
    else
    {
        fila_circular->primeiro = ( fila_circular->primeiro + 1 ) % MAX_FILA_C;
        fila_circular->tamanho--;
        return removido;
    }

}

ListaCircular *removerNoListaCircular( ListaCircular *lista )
{
    ListaCircular *novo = lista->ante,
                  *raiz = lista->prox;

    novo->prox = raiz;
    raiz->ante = novo;

    free( lista );

    return novo;

}

ListaCircular *copiarListaCircular( ListaCircular *original )
{
    ListaCircular *copia = criarListaCircular();
    ListaCircular *iter_ori = original->prox;

    while( iter_ori->valor_bin != '#' )
    {
        copia = inserirListaCircular( copia , iter_ori->valor_bin );
        iter_ori = iter_ori->prox;
    }

    return copia;

}

/*
void salvarTamanho()
{
    FILE *arquivo;

    if( arquivo = fopen( "c:/users/ec/desktop/testando.txt" , "ab" ) )
    {
        // Se já existe, adicionar. Se não existe, cria.
    }
    else
        arquivo = fopen( "c:/users/ec/desktop/testando.txt" , "wb");

    fread(buff, 1, sizeof buff, arquivo );

}*/

void percorrerArquivo( FILE *arquivo , ListaCircular *array_caminhos , FilaCircular *buffer_caminhos )
{

}


void percorrerDados( Arvore* arvore_huffman , ListaCircular *lista_principal , ListaCircular *array_caminhos[] , FilaCircular *buffer )
{
int it;
    if( arvore_huffman != NULL )
    {

    unsigned char codigo[2];
                  codigo[0] = arvore_huffman->caractere;
                  codigo[1] = 'a';
                  codigo[2] = '\0';

        if( eFolha( arvore_huffman ) )
        {
            codigo[1] = 'b';
            printf("\n %c\n",codigo[0] );
            array_caminhos[ codigo[0] ] = copiarListaCircular( lista_principal );
            ListaCircular *current = lista_principal->prox;
            current = current->prox;
            while(current->valor_bin != '#')
            {
                printf(" %c\n",current->valor_bin);
                current = current->prox;
            }
            bufferInserir( buffer , "1" );
            bufferInserir( buffer , codigo );

        }
        else
        {
            bufferInserir( buffer , "0" );
        }

        if ( ( buffer->tamanho >= 8 ) )
        {
            EscreverEmBin( buffer );
        }

        lista_principal = inserirListaCircular( lista_principal , '0' );

        percorrerDados( arvore_huffman->esquerda , lista_principal , array_caminhos , buffer );

        lista_principal = removerNoListaCircular( lista_principal );
        lista_principal = inserirListaCircular( lista_principal , '1' );


        percorrerDados( arvore_huffman->direita , lista_principal , array_caminhos , buffer );


        lista_principal = removerNoListaCircular( lista_principal );



    }
}

void criarCompactado( Arvore* arvore_huffman )
{
    ListaCircular *lista_principal = criarListaCircular(); //Lista circular usada para criar os caminhos de cada caractere.

    ListaCircular *array_caminhos[256]; // Array de listas circulares, uma lista para cada caractere.

    FilaCircular *buffer = criarFilaCircular();

    percorrerDados( arvore_huffman , lista_principal , array_caminhos , buffer );
/*
    if ( ( buffer->tamanho >= 8 ) )
    {
        EscreverEmBin( buffer );
    }*/

    FilaCircular *buffer_caminhos = criarFilaCircular();

    //percorrerArquivo( array_caminhos , buffer_caminhos );

}

/*
int main()
{

    FilaCircular *fila_circular = criarFilaCircular();
    EnfileirarFilaC(fila_circular, 'a');
    EnfileirarFilaC(fila_circular, 'b');
    EnfileirarFilaC(fila_circular, 'c');
    EnfileirarFilaC(fila_circular, 'd');
    EnfileirarFilaC(fila_circular, 'e');
    int i = 0;
    while( i < 5 )
    {
        printf("%c %d\n",fila_circular->valores[i],fila_circular->primeiro);
        i++;
    }


    ListaCircular *lista = criarListaCircular();
    ListaCircular *current = lista;
    lista = inserirListaCircular( lista , '0' );
    lista = inserirListaCircular( lista , '0' );
    lista = inserirListaCircular( lista , '0' );
    lista = inserirListaCircular( lista , '1' );
    lista = inserirListaCircular( lista , '2' );

    //lista = inserirListaCircular( lista , '2' );
    //lista = removerNoListaCircular( lista );

    while( current->valor_bin != '2' )
    {
        printf("%c\n", current->valor_bin );
        current = current->prox;
    }

    printf("%c\n", current->valor_bin );

    printf("\n");

    ListaCircular *copia = copiarListaCircular( lista->prox );
    current = copia->prox;
    while( current->valor_bin != '2' )
    {
        printf("%c\n", current->valor_bin );
        current = current->prox;
    }

    printf("%c\n", current->valor_bin );

}
*/
