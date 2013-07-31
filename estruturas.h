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

FilaCircular *criarFilaCircular();

ListaCircular *criarListaCircular();

int EnfileirarFilaC( FilaCircular *fila_circular , unsigned char valor );

ListaCircular *inserirListaCircular( ListaCircular *lista , unsigned char valor );

int DesenfileirarFilaC( FilaCircular *fila_circular );

ListaCircular *removerNoListaCircular( ListaCircular *lista );

ListaCircular *copiarListaCircular( ListaCircular *original );

void percorrerArquivo( FILE *arquivo , ListaCircular *array_caminhos , FilaCircular *buffer_caminhos );

void percorrerDados( Arvore* arvore_huffman , ListaCircular *lista_principal , ListaCircular *array_caminhos[] , FilaCircular *buffer );

void criarCompactado( Arvore* arvore_huffman );
