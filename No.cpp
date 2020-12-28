#include "No.h"
#include "Aresta.h"
#include <iostream>

using namespace std;

//Construtor
No::No(int id)
{
    this->id = id;
    this->peso = 0;
    this->grau_entrada = 0;
    this->grau_saida = 0;
    this->primeira_aresta = nullptr;
    this->ultima_aresta = nullptr;
    this->prox_no = nullptr;    
};

//Destrutor
No::~No(){

    Aresta* prox_aresta = this->primeira_aresta;

    while(prox_aresta != nullptr){

        Aresta* aux_edge = prox_aresta->getProxAresta();
        delete prox_aresta;
        prox_aresta = aux_edge;

    }

};

// Getters
Aresta* No::getPrimeiraAresta(){

    return this->primeira_aresta;

}

Aresta* No::getUltimaAresta(){

    return this->ultima_aresta;

}

int No::getId(){

    return this->id;

}

int No::getGrauEntrada(){

    return this->grau_entrada;

}

int No::getGrauSaida(){

    return this->grau_saida;

}

float No::getPeso(){

    return this->peso;

}

No* No::getProxNo(){

    return this->prox_no;

}

// Setters

void No::setProxNo(No* prox_no){

    this->prox_no = prox_no;

}

void No::setPeso(float peso){

    this->peso = peso;

}

// Outras Funções
void No::insereAresta(int id_alvo, float peso){
    // Verifies whether there are at least one edge in the No
    if(this->primeira_aresta != nullptr){
        // Allocating the new edge and keeping the integrity of the edge list
        Aresta* aresta = new Aresta(id_alvo);
        edge->setPeso(peso);
        this->ultima_aresta->setProxAresta(aresta);
        this->ultima_aresta = aresta;

    }
    else{
         // Allocating the new edge and keeping the integrity of the edge list
        this->primeira_aresta = new Aresta(id_alvo);
        this->primeira_aresta->setPeso(peso);
        this->ultima_aresta = this->primeira_aresta;

    }

}

void No::removeTodasArestas(){
    // Verifies whether there are at least one edge in the No
    if(this->primeira_aresta != nullptr){

        Aresta* next = nullptr;
        Aresta* aux = this->primeira_aresta;
        // Removing all edges of the No
        while(aux != nullptr){

            next = aux->getProxAresta();
            delete aux;

        }

    }

    this->primeira_aresta = this->ultima_aresta = nullptr;

}

int No::removeAresta(int id, bool direcionada, No* no_alvo){
    // Verifies whether the edge to remove is in the No
    if(this->buscaAresta(id)){

        Aresta* aux = this->primeira_aresta;
        Aresta* anterior = nullptr;
        // Searching for the edge to be removed
        while(aux->getIdAlvo() != id){

            previous = aux;
            aux = aux->getProxAresta();

        }
        // Keeping the integrity of the edge list
        if(anterior != nullptr)
            anterior->setProxAresta(aux->getProxAresta());

        else
            this->primeira_aresta = aux->getProxAresta();

        if(aux == this->ultima_aresta)
            this->ultima_aresta = anterior;

        if(aux->getProxAresta() == this->ultima_aresta)
            this->ultima_aresta = aux->getProxAresta();

        delete aux;
        // Verifies whether the graph is directed
        if(directed)
            this->diminuiGrauSaida();

        else{

            this->diminuiGrauSaida();
            target_No->diminuiGrauSaida();

        }

        return 1;

    }

    return 0;

}

bool No::buscaAresta(int id_alvo){
     // Verifies whether there are at least one edge in the No
    if(this->primeira_aresta != nullptr){
        // Searching for a specific edge of target id equal to target id
        for(Aresta* aux = this->primeira_aresta; aux != nullptr; aux = aux->getProxAresta())
            if(aux->getIdAlvo() == id_alvo)
                return true;

    }

    return false;

}

void No::somaGrauEntrada(){

    this->grau_entrada++;

}

void No::somaGrauSaida(){

    this->grau_saida++;

}

void No::diminuiGrauEntrada(){

    this->grau_entrada--;

}

void No::diminuiGrauSaida(){

    this->grau_saida--;

}

Aresta* No::possuiArestaEntre(int id_alvo)
{

    for(Aresta *auxAresta = this->primeira_aresta; auxAresta != nullptr; auxAresta = auxAresta->getProxAresta())
    {
        if(auxAresta->getIdAlvo() == id_alvo)
            return auxAresta;
    }
    return nullptr;
}
