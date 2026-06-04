#include "sistema.h"
#include <cmath>

float calcularDistanciaPlanetas(
    Planeta p1,
    Planeta p2
)
{
    return sqrt(
        pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2)
    );
}

void mostrarDistanciaEntrePlanetas(
    NoPlaneta* raiz,
    string nome1,
    string nome2
)
{
    NoPlaneta* p1 =
        buscarPlaneta(
            raiz,
            nome1
        );

    NoPlaneta* p2 =
        buscarPlaneta(
            raiz,
            nome2
        );

    if (p1 == NULL || p2 == NULL)
    {
        cout << "\nUm dos planetas nao foi encontrado.\n";
        return;
    }

    float distancia =
        calcularDistanciaPlanetas(
            p1->planeta,
            p2->planeta
        );

    cout << "\nDistancia entre "
         << nome1
         << " e "
         << nome2
         << " = "
         << distancia
         << endl;
}

void calcularDistanciaMenu()
{
    string planeta1;
    string planeta2;

    cout << "\nPrimeiro planeta: ";
    cin >> planeta1;

    cout << "Segundo planeta: ";
    cin >> planeta2;

    mostrarDistanciaEntrePlanetas(
        raizPlanetas,
        planeta1,
        planeta2
    );
}

void coletarPlanetas(
    NoPlaneta* raiz,
    Planeta vetor[],
    int& quantidade
)
{
    if(raiz == NULL)
    {
        return;
    }

    coletarPlanetas(
        raiz->esquerda,
        vetor,
        quantidade
    );

    vetor[quantidade] =
        raiz->planeta;

    quantidade++;

    coletarPlanetas(
        raiz->direita,
        vetor,
        quantidade
    );
}

void ordenarSobrevivencia(
    Planeta vetor[],
    int quantidade
)
{
    for(int i = 0; i < quantidade - 1; i++)
    {
        for(int j = 0; j < quantidade - i - 1; j++)
        {
            if(
                vetor[j].sobrevivencia <
                vetor[j + 1].sobrevivencia
            )
            {
                Planeta temp =
                    vetor[j];

                vetor[j] =
                    vetor[j + 1];

                vetor[j + 1] =
                    temp;
            }
        }
    }
}

void mostrarRankingSobrevivencia()
{
    if(raizPlanetas == NULL)
    {
        cout << "\nNenhum planeta cadastrado.\n";
        return;
    }

    Planeta vetor[100];

    int quantidade = 0;

    coletarPlanetas(
        raizPlanetas,
        vetor,
        quantidade
    );

    ordenarSobrevivencia(
        vetor,
        quantidade
    );

    cout << "\n=== RANKING DE SOBREVIVENCIA ===\n";

    for(int i = 0; i < quantidade; i++)
    {
        cout
            << i + 1
            << "º - "
            << vetor[i].nome
            << " ("
            << vetor[i].sobrevivencia
            << ")\n";
    }
}

void menuSistema()
{
    int opcao;

    do
    {
        cout << "\n=== MODULO SISTEMA ===\n";

        cout << "\n1 - Calcular distancia";
        cout << "\n2 - Ranking de sobrevivencia";
        cout << "\n3 - Informacoes do Sistema";
        cout << "\n4 - Sobre Integracao";
        cout << "\n0 - Voltar";

        cout << "\n\nOpcao: ";
        cin >> opcao;

        switch(opcao)
        {
            case 1:

                calcularDistanciaMenu();

                break;

            case 2:

                mostrarRankingSobrevivencia();

                break;

            case 3:

                cout << "\nSistema de Exploracao Espacial\n";

                cout << "\nModulos:";
                cout << "\n- ABB de Planetas";
                cout << "\n- Fila de Viagens";
                cout << "\n- Historico";
                cout << "\n- Eventos";
                cout << "\n- Ordenacao de Sobrevivencia";

                break;

            case 4:

                cout << "\nIntegracao realizada:\n";
                cout << "Planetas -> Sistema\n";
                cout << "ABB -> Ordenacao\n";
                cout << "Calculo de Distancias\n";

                break;

            case 0:

                break;

            default:

                cout << "\nOpcao invalida!\n";
        }

    } while(opcao != 0);
}
