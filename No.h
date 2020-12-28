#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include "Aresta.h" // Include of the Edge class

using namespace std;

// Definição da Classe Nó
class No{

    // Variáveis
    private:
        Aresta* primeira_aresta;
        Aresta* ultima_aresta;
        int id;
        unsigned int grau_entrada;
        unsigned int grau_saida;
        float peso;
        No* next_node;

    public:
        // Constructor
        No(int id);
        // Destructor
        ~No();
        // Getters
        Aresta* getPrimeiraAresta();
        Aresta* getUltimaAresta();
        int getId();
        int getGrauSaida();
        int getGrauEntrada();
        float getPeso();
        No* getProxNo();
        // Setters
        void setProxNo(No* no);
        void setPeso(float peso);
        // Other methods
        bool buscaAresta(int id_alvo);
        void insereAresta(int id_alvo, float peso);
        void removeTodasArestas();
        int removeAresta(int id, bool direcionado, No* no_alvo);
        void somaGrauSaida();
        void diminuiGrauSaida();
        void somaGrauEntrada();
        void diminuiGrauEntrada();
        Aresta* possuiArestaEntre(int id_alvo);
        // Auxiliar methods

};

#endif // NODE_H_INCLUDED
