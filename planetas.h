#ifndef PLANETAS_H
#define PLANETAS_H

#include <iostream>
#include <string>
using namespace std;

struct Planeta {
    string nome;
    int ordemSolar;
    float x;
    float y;
    float gravidade;
    string tipo;
    float sobrevivencia;
};

struct No {
    Planeta planeta;
    No* esquerda;
    No* direita;
};

No* criarNo( Planeta p);

No* inserirPlaneta(No* raiz, Planeta p);

void mostrarPlanetas(No* raiz);

No* buscarPlaneta(No* raiz, string nome);

#endif
