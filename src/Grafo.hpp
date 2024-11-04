#ifndef __GRAFO_HPP
#define __GRAFO_HPP

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Grafo {
    private:
        unordered_map<char, vector<char>> adjacencias;
    public:
        Grafo();
        void adicionarVertice(char vertice);
        void adicionarAresta(char origem, char destino);
        void exibirGrafo();
};

#endif 
