#include "historico.h"

// Ponteiros de controle
NoHistorico* inicio = NULL;
NoHistorico* fim = NULL;

// Registrar viagem
void registrarViagemHistorico(string destino) {

    NoHistorico* nova = new NoHistorico;

    nova->destino = destino;
    nova->proximo = NULL;
    nova->anterior = fim;

    if (inicio == NULL) {

        inicio = nova;
        fim = nova;

    } else {

        fim->proximo = nova;
        fim = nova;
    }

    cout << "Viagem para "
         << destino
         << " registrada com sucesso!\n";
}

// Mostrar histórico
void mostrarHistorico() {

    if (inicio == NULL) {

        cout << "Nenhuma viagem cadastrada.\n";
        return;
    }

    NoHistorico* atual = inicio;

    cout << "\n=== HISTORICO DE VIAGENS ===\n";

    while (atual != NULL) {

        cout << "- " << atual->destino << endl;
        atual = atual->proximo;
    }
}

// Navegar do fim para o início
void voltarHistorico() {

    if (fim == NULL) {

        cout << "Historico vazio.\n";
        return;
    }

    NoHistorico* atual = fim;

    cout << "\n=== VOLTANDO NO HISTORICO ===\n";

    while (atual != NULL) {

        cout << "- " << atual->destino << endl;
        atual = atual->anterior;
    }
}

void menuHistorico()
{
    int opcao;
    string destino;

    do
    {
        cout << "\n=== MODULO HISTORICO ===\n";

        cout << "1 - Registrar viagem\n";
        cout << "2 - Mostrar historico\n";
        cout << "3 - Voltar historico\n";
        cout << "0 - Voltar\n";

        cout << "\nOpcao: ";
        cin >> opcao;
        cin.ignore();

        switch(opcao)
        {
            case 1:
                cout << "Destino: ";
                getline(cin, destino);
                registrarViagemHistorico(destino);
                break;

            case 2:
                mostrarHistorico();
                break;

            case 3:
                voltarHistorico();
                break;
        }

    } while(opcao != 0);
}
