#ifndef AVL_H
#define AVL_H

typedef struct no {
    int info;
    struct no *esquerda;
    struct no *direita;
} No;

No* criarNo(int valor);
No* inserirBST(No* raiz, int valor);
No* rotacaoSimplesDireita(No* raiz);
No* rotacaoSimplesEsquerda(No* raiz);
No* rotacaoDuplaDireita(No* raiz);
No* rotacaoDuplaEsquerda(No* raiz);
No* aplicarRotacao(No* raiz, int tipo);
void imprimirPreOrdem(No* raiz);

#endif