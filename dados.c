#include <stdlib.h>
#include <stdio.h>
#include "teste3.h"
#include "estruturas.h"
#include "operacoesbinarias.h"
#include "entrada.c"

int main()
{

    Arvore *raiz = CriaArvoreBinaria('*');
    Arvore *pmdro = CriaArvoreBinaria('*');
    Arvore *pmdr = CriaArvoreBinaria('*');
    Arvore *pm = CriaArvoreBinaria('*');
    Arvore *dr = CriaArvoreBinaria('*');
    Arvore *alin = CriaArvoreBinaria('*');
    Arvore *in = CriaArvoreBinaria('*');
    Arvore *al = CriaArvoreBinaria('*');
    Arvore *of = CriaArvoreBinaria('O');
    Arvore *pf = CriaArvoreBinaria('P');
    Arvore *mf = CriaArvoreBinaria('M');
    Arvore *df = CriaArvoreBinaria('D');
    Arvore *rf = CriaArvoreBinaria('R');
    Arvore *iff = CriaArvoreBinaria('I');
    Arvore *nf = CriaArvoreBinaria('N');
    Arvore *af = CriaArvoreBinaria('A');
    Arvore *lf = CriaArvoreBinaria('L');

    raiz->esquerda = pmdro;
    raiz->direita = alin;

    pmdro->esquerda = pmdr;
    pmdro->direita = of;

    pmdr->esquerda = pm;
    pmdr->direita = dr;

    pm->esquerda = pf;
    pm->direita = mf;

    dr->esquerda = df;
    dr->direita = rf;

    alin->esquerda = in;
    alin->direita = al;


    in->esquerda = iff;
    in->direita = nf;

    al->esquerda = af;
    al->direita = lf;

    criarCompactado( raiz );

	//navegaRecursivo ("/home/ec/projetos/Compactador");

    return 0;

}
