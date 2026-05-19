#include "planetas.h"

No* criarNo(Planeta p) {
    No* novo = new No;

    novo->planeta = p;
    novo->esquerda = NULL;
    novo->direita = NULL;

    return novo;
}

No* inserirPlaneta(No* raiz, Planeta p) {

    if (raiz == NULL) {
        return criarNo(p);
    }

    if (p.ordemSolar < raiz->planeta.ordemSolar) {
        raiz->esquerda = inserirPlaneta(raiz->esquerda, p);
    } else {
        raiz->direita = inserirPlaneta(raiz->direita, p);
    }
    return raiz;
}