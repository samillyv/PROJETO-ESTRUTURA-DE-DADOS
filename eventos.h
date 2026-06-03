#ifndef EVENTOS_H
#define EVENTOS_H

#include <iostream>
#include <string>

using namespace std;

struct Evento {
    int id;
    string nave;
    string tipo;
    string descricao;
    string destino;
};

struct NoEvento {
    Evento dado;
    NoEvento* prox;
};

struct Pilha {
    NoEvento* topo;
    int tam;
};

void iniciar(Pilha &p);
bool vazia(Pilha &p);
void push(Pilha &p, Evento e);
Evento pop(Pilha &p);
void topo(Pilha &p);
void listar(Pilha &p);
void liberar(Pilha &p);

void menuEventos(Pilha &p);

#endif
