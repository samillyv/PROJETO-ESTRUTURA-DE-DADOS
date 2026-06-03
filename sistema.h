#ifndef SISTEMA_H
#define SISTEMA_H

#include "planetas.h"

float calcularDistanciaPlanetas(
    Planeta p1,
    Planeta p2
);

void mostrarDistanciaEntrePlanetas(
    NoPlaneta* raiz,
    string nome1,
    string nome2
);

void calcularDistanciaMenu();

void coletarPlanetas(
    NoPlaneta* raiz,
    Planeta vetor[],
    int& quantidade
);

void ordenarSobrevivencia(
    Planeta vetor[],
    int quantidade
);

void mostrarRankingSobrevivencia();

void menuSistema();

#endif
