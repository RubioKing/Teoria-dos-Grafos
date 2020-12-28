#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED

using namespace std;

// Definition of the Edge class
class Aresta{

    // Attributes
    private:
        int id_alvo;
        Aresta* proxima_aresta;
        float peso;

    public:
        // Constructor
        Aresta(int id_alvo);
        // Destructor
        ~Aresta();
        // Getters
        int getIdAlvo();
        Aresta* getProxAresta();
        float getPeso();
        // Setters
        void setProxAresta(Aresta* aresta);
        void setPeso(float peso); 

}; 

#endif // EDGE_H_INCLUDED