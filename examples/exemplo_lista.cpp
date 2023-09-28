#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class Grafo{
    int vertice;
    list<int> *adj; //ponteiro para um array contendo as listas de adjacencias

public :
    Grafo(int vertice); //construtor
    void adicionarAresta(int vertice1, int vertice2);
    bool Vizinho(int vertice1, int vertice2);

    int Graudesaida(int vertice);

};

Grafo::Grafo(int vertice){
    this->vertice = vertice;
    adj = new list<int>[vertice];
}

void Grafo::adicionarAresta(int vertice1, int vertice2){
    adj[vertice1].push_back(vertice2);
}

bool Grafo::Vizinho(int vertice1, int vertice2){
    if(find(adj[vertice1].begin(), adj[vertice1].end(), vertice2) != adj[vertice1].end())
        return true;
    else
        return false;
}

int Grafo::Graudesaida(int vertice){
    return adj[vertice].size();
}


int main(){

    Grafo grafo(4);

    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(0, 3);
    grafo.adicionarAresta(1, 2);
    grafo.adicionarAresta(3, 2);
    grafo.adicionarAresta(3, 1);

    cout << "Grau de saida do vertice 1: " << grafo.Graudesaida(1) << endl;
    cout << "Grau de saida do vertice 3: " << grafo.Graudesaida(3) << endl;
    cout << "Grau de saida do vertice 3: " << grafo.Graudesaida(2) << endl;

    if(grafo.Vizinho(0, 1))
        cout << "1 eh vizinho de 0" << endl;
    else
        cout << "1 nao eh vizinho de 0" << endl;

    if (grafo.Vizinho(3, 1))
        cout << "3 eh vizinho de 1" << endl;
    else
        cout << "3 nao eh vizinho de 1" << endl;

    return 0;

}