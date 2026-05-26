#include "planetas.h"

No *criarNo(Planeta p)
{
    No *novo = new No;

    novo->planeta = p;
    novo->esquerda = NULL;
    novo->direita = NULL;

    return novo;
}

No *inserirPlaneta(No *raiz, Planeta p)
{

    if (raiz == NULL)
    {
        return criarNo(p);
    }

    if (p.ordemSolar < raiz->planeta.ordemSolar)
    {
        raiz->esquerda = inserirPlaneta(raiz->esquerda, p);
    }
    else
    {
        raiz->direita = inserirPlaneta(raiz->direita, p);
    }
    return raiz;
}

void mostrarPlanetas(No *raiz)
{
    if (raiz != NULL)
    {
        mostrarPlanetas(raiz->esquerda);
        cout << "Planeta: " << raiz->planeta.nome << endl;
        cout << "Ordem Solar: " << raiz->planeta.ordemSolar << endl;
        cout << "Coordenadas: (" << raiz->planeta.x << ", " << raiz->planeta.y << ")" << endl;
        cout << "Gravidade: " << raiz->planeta.gravidade << endl;
        cout << "Tipo: " << raiz->planeta.tipo << endl;
        cout << "Sobrevivencia: " << raiz->planeta.sobrevivencia << endl;
        cout << "--------------------------" << endl;

        mostrarPlanetas(raiz->direita);
    }
}

No *buscarPlaneta(No *raiz, string nome)
{
    if (raiz == NULL)
    {
        return NULL;
    }
    if (raiz->planeta.nome == nome)
    {
        return raiz;
    }

    No *esquerda = buscarPlaneta(raiz->esquerda, nome);
    if (esquerda != NULL)
    {
        return esquerda;
    }
    return buscarPlaneta(raiz->direita, nome);
}
