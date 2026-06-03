#include "eventos.h"

void iniciar(Pilha &p) {
    p.topo = nullptr;
    p.tam = 0;
}

bool vazia(Pilha &p) {
    return p.topo == nullptr;
}

void push(Pilha &p, Evento e) {

    NoEvento* n = new NoEvento();

    n->dado = e;
    n->prox = p.topo;

    p.topo = n;
    p.tam++;

    cout << "\nEvento registrado: ["
         << e.tipo
         << "] Nave "
         << e.nave
         << " - "
         << e.descricao
         << endl;
}

Evento pop(Pilha &p) {

    if (vazia(p)) {

        cout << "\nPilha vazia, nenhum evento para revisar."
             << endl;

        Evento vazio = {-1, "", "", "", ""};

        return vazio;
    }

    NoEvento* temp = p.topo;

    Evento e = temp->dado;

    p.topo = temp->prox;

    delete temp;

    p.tam--;

    cout << "\nEvento removido: ["
         << e.tipo
         << "] Nave "
         << e.nave
         << endl;

    return e;
}

void topo(Pilha &p) {

    if (vazia(p)) {

        cout << "\nNenhum evento registrado ainda."
             << endl;

        return;
    }

    Evento &e = p.topo->dado;

    cout << "\n--- Evento mais recente ---" << endl;
    cout << "ID: " << e.id << endl;
    cout << "Nave: " << e.nave << endl;
    cout << "Tipo: " << e.tipo << endl;
    cout << "Descricao: " << e.descricao << endl;
    cout << "Destino: " << e.destino << endl;
}

void listar(Pilha &p) {

    if (vazia(p)) {

        cout << "\nNenhum evento na pilha."
             << endl;

        return;
    }

    cout << "\n=== Eventos registrados ("
         << p.tam
         << ") ==="
         << endl;

    NoEvento* atual = p.topo;

    int i = 1;

    while (atual != nullptr) {

        cout << "\n[" << i << "]";

        if (i == 1)
            cout << " <- mais recente";

        cout << endl;

        cout << "ID: " << atual->dado.id << endl;
        cout << "Nave: " << atual->dado.nave << endl;
        cout << "Tipo: " << atual->dado.tipo << endl;
        cout << "Descricao: " << atual->dado.descricao << endl;
        cout << "Destino: " << atual->dado.destino << endl;

        atual = atual->prox;

        i++;
    }
}

void liberar(Pilha &p) {

    while (!vazia(p)) {
        pop(p);
    }
}

void menuEventos(Pilha &p)
{
    int op;
    int id = p.tam + 1;

    do
    {
        cout << "\n=== MODULO EVENTOS ===\n";

        cout << "1 - Registrar evento\n";
        cout << "2 - Remover ultimo evento\n";
        cout << "3 - Ver evento mais recente\n";
        cout << "4 - Listar eventos\n";
        cout << "0 - Voltar\n";

        cout << "\nOpcao: ";
        cin >> op;
        cin.ignore();

        if(op == 1)
        {
            Evento e;

            e.id = id++;

            cout << "Nave: ";
            getline(cin, e.nave);

            cout << "Tipo: ";
            getline(cin, e.tipo);

            cout << "Descricao: ";
            getline(cin, e.descricao);

            cout << "Destino: ";
            getline(cin, e.destino);

            push(p, e);
        }
        else if(op == 2)
        {
            pop(p);
        }
        else if(op == 3)
        {
            topo(p);
        }
        else if(op == 4)
        {
            listar(p);
        }

    } while(op != 0);
}
