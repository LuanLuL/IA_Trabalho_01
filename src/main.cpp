#include <iostream>
#include <locale>

#include "Grafo.hpp"

using namespace std;

int main() {
    Grafo grafo;
    grafo.exibirGrafo();

    vector<char> caminho = grafo.bfs('U', 'E');
    grafo.exibirCaminho(caminho, 1);
    caminho = grafo.dfs('U', 'E');
    grafo.exibirCaminho(caminho, 2);
    cout << "\n";
    return 0;
}
