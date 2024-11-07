#ifndef __GRAFO_HPP
#define __GRAFO_HPP

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Grafo {
    private:
        unordered_map<char, vector<char>> adjacencias;
    public:
        Grafo();
        void adicionarVertice(char vertice);
        void adicionarAresta(char origem, char destino);
        void exibirGrafo();
        vector<char> bfs(char inicio, char objetivo);
        vector<char> dfs(char inicio, char objetivo);
        void exibirCaminho(const vector<char>& caminho, int busca);
};

#endif 
