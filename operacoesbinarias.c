#include <stdio.h>
#include <stdlib.h>
#include "teste3.h"
#include "estruturas.h"

unsigned int bit_ativado[] = {0x01,   /* 10000000 */
                              0x02,   /* 01000000 */
                              0x04,   /* 00100000 */
                              0x08,   /* 00010000 */
                              0x10,   /* 00001000 */
                              0x20,   /* 00000100 */
                              0x40,   /* 00000010 */
                              0x80};  /* 00000001 */


unsigned char RetornarCharBin( FilaCircular *buffer )
{

    unsigned char byte = 0;
    int n = 7;

    while( n >= 0 )
    {
        if ( ( buffer->tamanho > 0 ) )
        {
            if( ( buffer->valores[DesenfileirarFilaC( buffer )] == '1' ) )
            {//printf("1");
                byte |= bit_ativado[n];
            }//else printf("0");
        }
        n--;
    }
//printf("\n%c %d!!\n",byte , byte);
    return byte;

}

/* Escreve código de 8 Bytes binário no arquivo como 1 Byte,
recebe um buffer para controlar o vazamento de bits, e um
inteiro flag FDA(fim do arquivo) para sinalizar o fim do código
da árvore */

void EscreverEmBin( FilaCircular *buffer , int FDA ) 
{

    FILE * arquivo;
    unsigned char byte = 0;
    int n = 0;
    int n_max = ( buffer->tamanho ) / 8;

    if( arquivo = fopen( "/home/ec/testando.txt" , "ab" ) )
    {
        // Se já existe, adicionar. Se não existe, cria.
    }
    else
        arquivo = fopen( "/home/ec/testando.txt" , "wb");

	if ( FDA != 1 )
	{
   	 while( n < n_max )
    	 {
       	 fputc( RetornarCharBin( buffer ) , arquivo );
       	 n++;
    	 }
	}
	else
	{
   	 while( buffer->tamanho > 0 )
    	 {
       	 fputc( RetornarCharBin( buffer ) , arquivo );
       	 n++;
    	 }
	}


    fclose( arquivo );

}

void bufferInserir( FilaCircular *buffer , unsigned char *elemento )
{
    int n = 7;

    if( elemento[1] == 'b' )
    {//printf("\n");
        while( n >= 0 )
        {
//printf("\n%c\n",elemento[0]);

            if ( elemento[0] & bit_ativado[n] )
            {
                EnfileirarFilaC( buffer , '1' ); //printf("1");
            }
            else
            {
                EnfileirarFilaC( buffer , '0' ); //printf("0");
            }

            n--;
        }//printf("\n");
    }
    else
    {
        EnfileirarFilaC( buffer , elemento[0] ); //printf("\n%c\n",elemento[0]);
    }
    int i = 0;
    while( i < 100 )
    {
        //printf("%c %d!\n", buffer->valores[i], i );
        i++;
    }
    //printf("\n");
}
/*
int main()
{
printf("Start\n");
    //char chars[] = {'1','0','0','0','0','0','1','0','1','0','0','0','0','0','1','0','0','1','0','0','0','0','1','0','\0'};
    //EscreverEmBin(chars);
    FilaCircular *fila_circular = criarFilaCircular();

    bufferInserir( fila_circular , "0" );
    bufferInserir( fila_circular , "1" );
    bufferInserir( fila_circular , "0" );
    bufferInserir( fila_circular , "0" );
    bufferInserir( fila_circular , "0" );
    bufferInserir( fila_circular , "0" );
    bufferInserir( fila_circular , "0" );
    bufferInserir( fila_circular , "1" );

    bufferInserir( fila_circular , "0" );
    bufferInserir( fila_circular , "1" );
    bufferInserir( fila_circular , "0" );
    bufferInserir( fila_circular , "0" );
    bufferInserir( fila_circular , "0" );
    bufferInserir( fila_circular , "0" );
    bufferInserir( fila_circular , "1" );

printf("!!!!!%d!!!\n",fila_circular->tamanho);
    EscreverEmBin( fila_circular );

}
*/
