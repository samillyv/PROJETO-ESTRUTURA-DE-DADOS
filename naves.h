#ifndef NAVES_H
#define NAVES_H

#include <iostream>
#include <queue>

using namespace std;

// Dados da nave
struct Nave {
    string nome;
    int capacidade;
    float velocidade;
};

// Dados da viagem
struct Viagem {
    Nave nave;
    string origem;
    string destino;
    float distancia;
};

// Fila principal
extern queue<Viagem> filaViagens;

// Protótipos
void adicionarViagem();
void processarViagem();
void mostrarFila();
void mostrarPrimeiraViagem();

void menuNaves();

#endif
