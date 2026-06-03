#ifndef HISTORICO_H
#define HISTORICO_H

#include <iostream>
#include <string>

using namespace std;

// Nó da lista duplamente encadeada
struct NoHistorico {
    string destino;
    NoHistorico* anterior;
    NoHistorico* proximo;
};

// Funções
void registrarViagemHistorico(string destino);
void mostrarHistorico();
void voltarHistorico();

void menuHistorico();

#endif
