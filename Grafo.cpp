#include "Grafo.h"
#include "No.h"
#include "Aresta.h"
#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <list>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <float.h>
#include <iomanip>

using namespace std;

// Constructor
Grafo::Grafo(int ordem, bool direcionado, bool aresta_ponderada, bool no_ponderado)
{
    this->ordem = ordem;
    this->direcionado = direcionado;
    this->aresta_ponderada = aresta_ponderada;
    this->no_ponderado = no_ponderado;
    this->primeiro_no = this->ultimo_no = nullptr;
    this->numero_arestas = 0;
}

Grafo::Grafo()
{
}

// Destructor
Grafo::~Grafo()
{

    No *proximo_no = this->primeiro_no;

    while (proximo_no != nullptr)
    {

        proximo_no->removeTodasArestas();
        No *aux_no = proximo_no->getProxNo();
        delete proximo_no;
        proximo_no = aux_no;
    }
}

// Getters
int Grafo::getOrdem()
{

    return this->ordem;
}

int Grafo::getNumeroArestas()
{

    return this->numero_arestas;
}

bool Grafo::getDirecionado()
{

    return this->direcionado;
}

bool Grafo::getArestaPonderada()
{

    return this->aresta_ponderada;
}

bool Grafo::getNoPonderado()
{

    return this->no_ponderado;
}

No *Grafo::getPrimeiroNo()
{

    return this->primeiro_no;
}

No *Grafo::getUltimoNo()
{

    return this->ultimo_no;
}

// Other methods
/*
    The outdegree attribute of nodes is used as a counter for the number of edges in the graph.
    This allows the correct updating of the numbers of edges in the graph being direcionado or not.
*/
void Grafo::insereNo(int id)
{
    if (this->getNo(id) != nullptr)
    {
        return;
    }

    int quant = this->getOrdem();
    No *p = new No(id);

    if (ultimo_no == nullptr)
    {
        ultimo_no = p;
        primeiro_no = p;
    }
    else
    {
        this->ultimo_no->setProxNo(p);
        this->ultimo_no = p;
    }
}

void Grafo::insereAresta(int id, int id_alvo, float peso)
{
    if (!this->BuscaNo(id))
    {
        this->BuscaNo(id);
    }

    if (!this->BuscaNo(id_alvo))
    {
        this->insereNo(id_alvo);
    }

    No *saida = this->getNo(id);
    saida->insereAresta(id_alvo, peso);
    No *entrada = this->getNo(id_alvo);
    entrada->insereAresta(id, peso);
    saida->somaGrauSaida();
    entrada->somaGrauEntrada();

    numero_arestas++;
}

void Grafo::removeNo(int id)
{
    No *p = this->getNo(id);

    if (p == nullptr)
    {
        return;
    }

    No *q = this->primeiro_no;

    if (p == primeiro_no)
    {
        primeiro_no = p->getProxNo();
        delete p;
        return;
    }

    for (; q->getProxNo() != p; q = q->getProxNo())
        ;

    if (p->getProxNo() == nullptr)
    {
        this->ultimo_no = q;
    }
    else
    {
        q->setProxNo(p->getProxNo());
    }
    delete p;
}

bool Grafo::BuscaNo(int id)
{
    No *p = this->primeiro_no;
    for (; p != nullptr;)
    {
        if (p->getId() == id)
            return true;
        p = p->getProxNo();
    }
    return false;
}

No *Grafo::getNo(int id)
{
    No *p = this->primeiro_no;
    for (; p != nullptr;)
    {
        if (p->getId() == id)
            return p;
        p = p->getProxNo();
    }
    return nullptr;
}

//Function that verifies if there is a path between two nodes
bool Grafo::depthFirstSearch(int initialId, int targetId)
{
}

void Grafo::breadthFirstSearch(ofstream &output_file)
{
}

Grafo *Grafo::getComplement()
{
}

//A function that returns a subjacent of a direcionado graph, which is a graph which the arcs have opposite directions to the original graph
Grafo *Grafo::getSubjacent()
{
}

bool Grafo::connectedGraph()
{
}

bool Grafo::hasCircuit()
{
}

float **Grafo::floydMarshall()
{
}

float *Grafo::dijkstra(int id)
{
}
