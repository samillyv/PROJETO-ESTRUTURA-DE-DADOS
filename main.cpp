#include "planetas.h"
#include "naves.h"
#include "historico.h"
#include "eventos.h"
#include "sistema.h"

int main()
{
    Pilha pilhaEventos;

    iniciar(pilhaEventos);
    carregarPlanetas();

    int opcao;

    do
    {
        cout << "\n================================";
        cout << "\n SISTEMA DE EXPLORACAO ESPACIAL";
        cout << "\n================================";

        cout << "\n1 - Planetas";
        cout << "\n2 - Naves";
        cout << "\n3 - Historico";
        cout << "\n4 - Eventos";
        cout << "\n5 - Sistema";
        cout << "\n0 - Sair";

        cout << "\n\nOpcao: ";
        cin >> opcao;

        switch(opcao)
        {
            case 1:
                menuPlanetas();
                break;

            case 2:
                menuNaves();
                break;

            case 3:
                menuHistorico();
                break;

            case 4:
                menuEventos(pilhaEventos);
                break;

            case 5:
                menuSistema();
                break;

            case 0:
                cout << "\nEncerrando sistema...\n";
                break;

            default:
                cout << "\nOpcao invalida!\n";
        }

    } while(opcao != 0);

    liberar(pilhaEventos);

    return 0;
}
