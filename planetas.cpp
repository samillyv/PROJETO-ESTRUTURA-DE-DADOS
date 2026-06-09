#include "planetas.h"

NoPlaneta* raizPlanetas = NULL;

NoPlaneta* criarNo(Planeta p)
{
    NoPlaneta* novo = new NoPlaneta;

    novo->planeta = p;
    novo->esquerda = NULL;
    novo->direita = NULL;

    return novo;
}

NoPlaneta* inserirPlaneta(NoPlaneta* raiz, Planeta p)
{
    if (raiz == NULL)
    {
        return criarNo(p);
    }

    if (p.ordemSolar < raiz->planeta.ordemSolar)
    {
        raiz->esquerda =
            inserirPlaneta(raiz->esquerda, p);
    }
    else
    {
        raiz->direita =
            inserirPlaneta(raiz->direita, p);
    }

    return raiz;
}

void mostrarPlanetas(NoPlaneta* raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    mostrarPlanetas(raiz->esquerda);

    cout << "\n--------------------------\n";
    cout << "Planeta: " << raiz->planeta.nome << endl;
    cout << "Ordem Solar: " << raiz->planeta.ordemSolar << endl;
    cout << "Coordenadas: ("
     << raiz->planeta.x << ", "
     << raiz->planeta.y << ", "
     << raiz->planeta.z << ")"
     << endl;
    cout << "Gravidade: " << raiz->planeta.gravidade << endl;
    cout << "Tipo: " << raiz->planeta.tipo << endl;
    cout << "Sobrevivencia: "
         << raiz->planeta.sobrevivencia << endl;
    cout << "--------------------------\n";

    mostrarPlanetas(raiz->direita);
}

NoPlaneta* buscarPlaneta(
    NoPlaneta* raiz,
    string nome
)
{
    if (raiz == NULL)
    {
        return NULL;
    }

    if (raiz->planeta.nome == nome)
    {
        return raiz;
    }

    NoPlaneta* esquerda =
        buscarPlaneta(
            raiz->esquerda,
            nome
        );

    if (esquerda != NULL)
    {
        return esquerda;
    }

    return buscarPlaneta(
        raiz->direita,
        nome
    );
}

void menuPlanetas()
{
    int opcao;

    do
    {
        cout << "\n=== MODULO PLANETAS ===\n";

        cout << "\n1 - Cadastrar planeta";
        cout << "\n2 - Buscar planeta";
        cout << "\n3 - Mostrar todos";
        cout << "\n0 - Voltar";

        cout << "\n\nOpcao: ";
        cin >> opcao;

        switch(opcao)
        {
            case 1:
            {
                Planeta p;

                cout << "\nNome: ";
                cin >> p.nome;

                NoPlaneta* existente =
                    buscarPlaneta(
                        raizPlanetas,
                        p.nome
                    );

                    if(existente != NULL) {
                        cout << "\nJa existe um planeta com esse nome, verifique em 'buscar planeta'.\n";
                        break;
                    }

                cout << "Ordem Solar: ";
                cin >> p.ordemSolar;

                cout << "Coordenada X: ";
                cin >> p.x;

                cout << "Coordenada Y: ";
                cin >> p.y;
 
                cout << "Coordenada Z: ";
                cin >> p.z;

                cout << "Gravidade: ";
                cin >> p.gravidade;

                cout << "Tipo: ";
                cin >> p.tipo;

                cout << "Sobrevivencia: ";
                cin >> p.sobrevivencia;

                raizPlanetas =
                    inserirPlaneta(
                        raizPlanetas,
                        p
                    );

                cout << "\nPlaneta cadastrado com sucesso!\n";

                break;
            }

            case 2:
            {
                string nome;

                cout << "\nNome do planeta: ";
                cin >> nome;

                NoPlaneta* encontrado =
                    buscarPlaneta(
                        raizPlanetas,
                        nome
                    );

                if(encontrado == NULL)
                {
                    cout << "\nPlaneta nao encontrado.\n";
                }
                else
                {
                    cout << "\nPlaneta encontrado!\n";

                    cout << "Nome: "
                         << encontrado->planeta.nome
                         << endl;

                    cout << "Ordem Solar: "
                         << encontrado->planeta.ordemSolar
                         << endl;

                    cout << "Coordenadas: ("
                         << encontrado->planeta.x
                         << ", "
                         << encontrado->planeta.y
                         << ", "
                         << encontrado->planeta.z
                         << ")\n";

                    cout << "Gravidade: "
                         << encontrado->planeta.gravidade
                         << endl;

                    cout << "Tipo: "
                         << encontrado->planeta.tipo
                         << endl;

                    cout << "Sobrevivencia: "
                         << encontrado->planeta.sobrevivencia
                         << endl;
                }

                break;
            }

            case 3:

                if(raizPlanetas == NULL)
                {
                    cout << "\nNenhum planeta cadastrado.\n";
                }
                else
                {
                    mostrarPlanetas(
                        raizPlanetas
                    );
                }

                break;

            case 0:

                cout << "\nRetornando...\n";
                break;

            default:

                cout << "\nOpcao invalida!\n";
        }

    } while(opcao != 0);
}

void carregarPlanetas()
{
Planeta p1 = {"Mercurio", 1, 39, 15, 8, 3.7, "Terrestre", 0.2};
Planeta p2 = {"Venus", 2, 72, 30, 12, 8.87, "Terrestre", 0.3};
Planeta p3 = {"Terra", 3, 100, 45, 20, 9.81, "Terrestre", 1.0};
Planeta p4 = {"Marte", 4, 152, 60, 35, 3.71, "Terrestre", 0.5};
Planeta p5 = {"Jupiter", 5, 520, 120, 70, 24.79, "Gasoso", 0.1};
Planeta p6 = {"Saturno", 6, 958, 200, 120, 10.44, "Gasoso", 0.05};
Planeta p7 = {"Urano", 7, 1920, 350, 180, 8.69, "Gasoso", 0.02};
Planeta p8 = {"Netuno", 8, 3005, 500, 250, 11.15, "Gasoso", 0.01};


    raizPlanetas = inserirPlaneta(raizPlanetas, p1);
    raizPlanetas = inserirPlaneta(raizPlanetas, p2);
    raizPlanetas = inserirPlaneta(raizPlanetas, p3);
    raizPlanetas = inserirPlaneta(raizPlanetas, p4);
    raizPlanetas = inserirPlaneta(raizPlanetas, p5);
    raizPlanetas = inserirPlaneta(raizPlanetas, p6);
    raizPlanetas = inserirPlaneta(raizPlanetas, p7);
    raizPlanetas = inserirPlaneta(raizPlanetas, p8);
}