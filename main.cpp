#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "Grafo.h"

using namespace std;

Grafo *le(ifstream &entrada)
{
    
}

int menu()
{
    int selecao;
    cout << "----------------------------------" << endl;
    cout << "   Subconjunto dominante minimo" << endl;
    cout << "----------------------------------" << endl;
    cout << "               MENU" << endl;
    cout << "----------------------------------" << endl;
    cout << " Opcao | Descricao" << endl;
    cout << "----------------------------------" << endl;
    cout << "  [1]  | Subgrafo Induzido" << endl;
    cout << "  [2]  | Caminho Minimo (Djkstra)" << endl;
    cout << "  [3]  | Caminho Minimo (Floyd)" << endl;
    cout << "  [4]  | Arvore Geradora Mínima (Prim)" << endl;
    cout << "  [5]  | Arvore Geradora Mínima (Kruskal)" << endl;
    cout << "  [6]  | Busca em largura" << endl;
    cout << "  [7]  | Ordenação topológica de um DAG" << endl;
    cout << "  [0]  | Sair" << endl;
    cout << "----------------------------------" << endl;
    cin >> selecao;

    return selecao;
}

void selecionar(int selecao, Grafo *grafo, ofstream &saida)
{
    switch (selecao)
    {
    case 1: {
        //grafo->mostrarGrafo(saida);
        //É PRA IMPLEMENTAR ESSA PORRA TODA.
        break;
    }
    default:
        break;
    }
}

int main(int argc, char *argv[])
{
    ifstream entrada;
    ofstream saida;
    Grafo *grafo = new Grafo();

    if (argc != 6)
    {
        cout << "Entrada esperada: execGrupoX <arquivo_entrada> <arquivo_saida> <Opc_Direc> <Opc_Peso_Aresta> <Opc_Peso_Nos>" << endl;
        return 1;
    }

    entrada.open(argv[1], ios::in);
    saida.open(argv[2], ios::out | ios::trunc);

    if (entrada.is_open())
    {
        grafo = le(entrada);
    }
    else
    {
        cout << "Não foi possível abrir o arquivo " << argv[1] << endl;
    }

    saida << endl
          << "------------------------------" << endl
          << "        FUNCIONALIDADES" << endl
          << "------------------------------" << endl;

    for (int selecao = menu(); selecao != 0; selecao = menu())
    {
        selecionar(selecao, grafo, saida); //FICA IMPRIMINDO O MENU IGUAL UM BURRO SEM PARAR.
    }
    entrada.close();
    saida.close();
    delete grafo;
    return 0;
}