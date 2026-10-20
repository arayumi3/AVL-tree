#include <stdio.h>
#include <stdlib.h>
#include "AVL_H.h"

No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->info = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

No* inserirBST(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->info) {
        raiz->esquerda = inserirBST(raiz->esquerda, valor);
    } else if (valor > raiz->info) {
        raiz->direita = inserirBST(raiz->direita, valor);
    }
    return raiz;
}

No* rotacaoSimplesDireita(No* raiz) {
    No* aux = raiz->esquerda;
    raiz->esquerda = aux->direita;
    aux->direita = raiz;
    return aux;
}

No* rotacaoSimplesEsquerda(No* raiz) {
    No* aux = raiz->direita;
    raiz->direita = aux->esquerda;
    aux->esquerda = raiz;
    return aux;
}

No* rotacaoDuplaDireita(No* raiz) {
    raiz->esquerda = rotacaoSimplesEsquerda(raiz->esquerda);
    return rotacaoSimplesDireita(raiz);
}

No* rotacaoDuplaEsquerda(No* raiz) {
    raiz->direita = rotacaoSimplesDireita(raiz->direita);
    return rotacaoSimplesEsquerda(raiz);
}

No* aplicarRotacao(No* raiz, int tipo) {

    switch (tipo) {
        case 1: return rotacaoSimplesDireita(raiz);
        case 2: return rotacaoSimplesEsquerda(raiz);
        case 3: return rotacaoDuplaDireita(raiz);
        case 4: return rotacaoDuplaEsquerda(raiz);
        default: return raiz;
    }
}

void imprimirPreOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->info);
        imprimirPreOrdem(raiz->esquerda);
        imprimirPreOrdem(raiz->direita);
    }
}