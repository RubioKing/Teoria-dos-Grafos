#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include "No.h"
#include <fstream>
#include <stack>
#include <list>

using namespace std;

class Grafo{

    //Atributes
    private:
        int ordem;
        int numero_arestas;
        bool direcionado;
        bool aresta_ponderada;
        bool no_ponderado;
        No* primeiro_no;
        No* ultimo_no;

    public:
        //Constructor
        Grafo(int ordem, bool direcionado, bool aresta_ponderada, bool no_ponderado);
        //Destructor
        ~Grafo();
        //Getters
        int getOrdem();
        int getNumeroArestas();
        bool getDirecionado();
        bool getArestaPonderada();
        bool getNoPonderado();
        No* getPrimeiroNo();
        No* getUltimoNo();
        //Other methods
        void insereNo(int id);
        void insereAresta(int id, int id_alvo, float peso);
        void removeNo(int id);
        bool BuscaNo(int id);
        No* getNo(int id);
        // ****************************TRADUZIR FUNÇÕES ABAIXO****************************
        bool depthFirstSearch(int initialId,int targetId);
        void breadthFirstSearch(ofstream& output_file);
        Grafo* getComplement();
        Grafo* getSubjacent();
        bool hasCircuit();
        bool connectedGraph();
        float** floydMarshall();
        float* dijkstra(int id);

    private:
        //Auxiliar methods

};

#endif // GRAPH_H_INCLUDED
