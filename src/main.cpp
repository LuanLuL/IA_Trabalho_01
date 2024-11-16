#include <iostream>
#include <locale>
#include <chrono>

#include "Grafo.hpp"

using namespace std;

int main() {
    Grafo grafo;
    grafo.exibirGrafo();

    double tempo_bfs, tempo_dfs;
    size_t max_tamanho_fila = 0, max_tamanho_pilha = 0;
    size_t tamanho_caminho_bfs = 0, tamanho_caminho_dfs = 0;
    bool dfs_otimo = false;

    auto inicio_bfs = chrono::high_resolution_clock::now();
    vector<char> caminho_bfs = grafo.bfs('U', 'E', &max_tamanho_fila);
    auto fim_bfs = chrono::high_resolution_clock::now();
    tempo_bfs = chrono::duration<double, milli>(fim_bfs - inicio_bfs).count();
    tamanho_caminho_bfs = caminho_bfs.size() - 1;
    grafo.exibirCaminho(caminho_bfs, 1);
    cout << "Tempo de execução do BFS: " << tempo_bfs << "ms\n";
    cout << "Consumo de memória do BFS: " << max_tamanho_fila << " elementos na fila\n";
    cout << "Tamanho do caminho encontrado pelo BFS: " << tamanho_caminho_bfs << " arestas\n";


    auto inicio_dfs = chrono::high_resolution_clock::now();
    vector<char> caminho_dfs = grafo.dfs('U', 'E', &max_tamanho_pilha);
    auto fim_dfs = chrono::high_resolution_clock::now();
    tempo_dfs = chrono::duration<double, milli>(fim_dfs - inicio_dfs).count();
    tamanho_caminho_dfs = caminho_dfs.size() -1;
    grafo.exibirCaminho(caminho_dfs, 2);
    cout << "Tempo de execução do DFS: " << tempo_dfs << "ms\n";
    cout << "Consumo de memória do DFS: " << max_tamanho_pilha << " elementos na pilha\n";
    cout << "Tamanho do caminho encontrado pelo DFS: " << tamanho_caminho_dfs << " arestas\n";

    if(!caminho_bfs.empty() && !caminho_dfs.empty()){
        dfs_otimo = (tamanho_caminho_dfs == tamanho_caminho_bfs);
    }

    cout << "\n==================== COMPARAÇÃO DOS RESULTADOS ====================\n";
    cout << "Algoritmo\t| Tempo de Execução\t| Consumo de Memória\t| Optimalidade\n";
    cout << "-------------------------------------------------------------------\n";
    cout << "BFS\t\t| " << tempo_bfs << "ms\t\t| " << max_tamanho_fila << " elementos\t\t| Ótimo\n";
    cout << "DFS\t\t| " << tempo_dfs << "ms\t\t| " << max_tamanho_pilha << " elementos\t\t| ";
    if (dfs_otimo) {
        cout << "Ótimo\n";
    } else {
        cout << "Não Ótimo\n";
    }
    cout << "===================================================================\n";


    cout << "\n";
    return 0;
}
