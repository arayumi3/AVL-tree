#include <stdio.h>
#include <stdlib.h>
#include "AVL_H.h"

int main() {
    No* raiz = NULL;

    //arvore desbalanceada para a esquerda
    raiz = inserirBST(raiz, 30);
    raiz = inserirBST(raiz, 20);
    raiz = inserirBST(raiz, 10);

    printf("Arvore Original (Pre-ordem): ");
    imprimirPreOrdem(raiz);
    printf("\n");

    printf("");

    printf("Aplicando Rotacao Simples a Direita\n");
    raiz = aplicarRotacao(raiz, 1);

    printf("Apos Rotacao (Pre-ordem): ");
    imprimirPreOrdem(raiz);
    printf("\n");

    //teste dp caso de rotacao dupla
    raiz = NULL; 
    raiz = inserirBST(raiz, 30);
    raiz = inserirBST(raiz, 10);
    raiz = inserirBST(raiz, 20);
    
    printf("\nNova Arvore(Pre-ordem): ");
    imprimirPreOrdem(raiz);
    printf("\n");

    printf("Aplicando Rotacao Dupla a Direita\n");
    raiz = aplicarRotacao(raiz, 3);
    
    printf("Apos Rotacao Dupla (Pre-ordem): ");
    imprimirPreOrdem(raiz);
    printf("\n");

    return 0;
}