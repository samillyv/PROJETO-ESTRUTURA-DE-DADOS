#include "naves.h"
#include "historico.h"
#include <limits>

using namespace std;

// Fila principal
queue<Viagem> filaViagens;

// Adicionar viagem
void adicionarViagem()
{

    Viagem v;

    cout << "\nCadastrar viagem\n";

    cout << "Nome da nave: ";
    cin >> v.nave.nome;

    cout << "Capacidade: ";
    while (!(cin >> v.nave.capacidade))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Digite um numero inteiro valido: ";
    }

    cout << "Velocidade (km/h): ";
    while (!(cin >> v.nave.velocidade))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Digite um numero valido: ";
    }

    cout << "Origem: ";
    cin >> v.origem;

    cout << "Destino: ";
    cin >> v.destino;

    cout << "Distancia (km): ";
    while (!(cin >> v.distancia))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Digite um numero valido: ";
    }

    filaViagens.push(v);

    cout << "\nViagem adicionada!\n";
}

// Processar primeira viagem
void processarViagem()
{
    if (filaViagens.empty())
    {
        cout << "\nFila vazia!\n";
        return;
    }

    Viagem v = filaViagens.front();

    float tempo = v.distancia / v.nave.velocidade;

    cout << "\nProcessando viagem...\n";

    cout << "Nave: "
         << v.nave.nome
         << endl;

    cout << "Origem: "
         << v.origem
         << endl;

    cout << "Destino: "
         << v.destino
         << endl;

    int horas = (int)tempo;
    int minutos = (tempo - horas) * 60;

    cout << "Tempo estimado: "
         << horas
         << " horas e " << minutos << " minutos\n";

    // INTEGRACAO COM HISTORICO
    registrarViagemHistorico(
        v.destino);

    filaViagens.pop();

    cout << "\nViagem concluida!\n";
}

// Mostrar fila completa
void mostrarFila()
{

    if (filaViagens.empty())
    {
        cout << "\nFila vazia!\n";
        return;
    }

    queue<Viagem> copia = filaViagens;

    int posicao = 1;

    cout << "\nFila de viagens\n";

    while (!copia.empty())
    {

        Viagem v = copia.front();

        cout << "\nPosicao " << posicao << endl;
        cout << "Nave: " << v.nave.nome << endl;
        cout << "Origem: " << v.origem << endl;
        cout << "Destino: " << v.destino << endl;

        copia.pop();
        posicao++;
    }
}

// Mostrar primeira viagem
void mostrarPrimeiraViagem()
{

    if (filaViagens.empty())
    {
        cout << "\nFila vazia!\n";
        return;
    }

    Viagem v = filaViagens.front();

    cout << "\nPrimeira viagem da fila\n";

    cout << "Nave: " << v.nave.nome << endl;
    cout << "Origem: " << v.origem << endl;
    cout << "Destino: " << v.destino << endl;
}

void menuNaves()
{

    int opcao;

    do
    {

        cout << "\n=== GERENCIAMENTO DE NAVES ===\n";

        cout << "\n1 - Adicionar viagem";
        cout << "\n2 - Processar viagem";
        cout << "\n3 - Mostrar fila";
        cout << "\n4 - Mostrar primeira viagem";
        cout << "\n0 - Voltar";

        cout << "\n\nOpcao: ";
        cin >> opcao;

        switch (opcao)
        {

        case 1:
            adicionarViagem();
            break;

        case 2:
            processarViagem();
            break;

        case 3:
            mostrarFila();
            break;

        case 4:
            mostrarPrimeiraViagem();
            break;

        case 0:
            cout << "\nRetornando...\n";
            break;

        default:
            cout << "\nOpcao invalida!\n";
        }

    } while (opcao != 0);
}
