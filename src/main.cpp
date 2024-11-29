#include <iostream>
#include <locale>
#include <chrono>

#include "Grafo.hpp"

using namespace std;

bool testarCompletudeBFS(Grafo& grafo);
bool testarCompletudeDFS(Grafo& grafo);
void medirDesempenhoBFS(Grafo& grafo, double& tempo, size_t& max_tamanho_fila, size_t& tamanho_caminho);
void medirDesempenhoDFS(Grafo& grafo, double& tempo, size_t& max_tamanho_pilha, size_t& tamanho_caminho);
void exibirComparacao(double tempo_bfs, size_t max_tamanho_fila, size_t tamanho_caminho_bfs, bool bfs_completo, double tempo_dfs, size_t max_tamanho_pilha, size_t tamanho_caminho_dfs, bool dfs_otimo, bool dfs_completo);

int main() {
    Grafo grafo;
    grafo.exibirGrafo();

    double tempo_bfs, tempo_dfs;
    size_t max_tamanho_fila = 0, max_tamanho_pilha = 0;
    size_t tamanho_caminho_bfs = 0, tamanho_caminho_dfs = 0;
    bool bfs_completo, dfs_completo, dfs_otimo = false;

    bfs_completo = testarCompletudeBFS(grafo);
    dfs_completo = testarCompletudeDFS(grafo);

    medirDesempenhoBFS(grafo, tempo_bfs, max_tamanho_fila, tamanho_caminho_bfs);
    medirDesempenhoDFS(grafo, tempo_dfs, max_tamanho_pilha, tamanho_caminho_dfs);

    if (tamanho_caminho_dfs == tamanho_caminho_bfs) dfs_otimo = true;

    exibirComparacao(tempo_bfs, max_tamanho_fila, tamanho_caminho_bfs, bfs_completo, tempo_dfs, max_tamanho_pilha, tamanho_caminho_dfs, dfs_otimo, dfs_completo);

    return 0;
}


bool testarCompletudeBFS(Grafo& grafo) {
    size_t max_tamanho_fila = 0;
    vector<char> caminho = grafo.bfs('U', 'E', &max_tamanho_fila);
    if (caminho.empty()) return false;

    return true;
}

bool testarCompletudeDFS(Grafo& grafo) {
    size_t max_tamanho_pilha = 0;
    vector<char> caminho = grafo.dfs('U', 'E', &max_tamanho_pilha);
    if (caminho.empty()) return false;

    return true;
}

void medirDesempenhoBFS(Grafo& grafo, double& tempo, size_t& max_tamanho_fila, size_t& tamanho_caminho) {
    auto inicio = chrono::high_resolution_clock::now();
    vector<char> caminho = grafo.bfs('U', 'E', &max_tamanho_fila);
    auto fim = chrono::high_resolution_clock::now();
    tempo = chrono::duration<double, milli>(fim - inicio).count();
    tamanho_caminho = caminho.size() - 1;
    grafo.exibirCaminho(caminho, 1);
}

void medirDesempenhoDFS(Grafo& grafo, double& tempo, size_t& max_tamanho_pilha, size_t& tamanho_caminho) {
    auto inicio = chrono::high_resolution_clock::now();
    vector<char> caminho = grafo.dfs('U', 'E', &max_tamanho_pilha);
    auto fim = chrono::high_resolution_clock::now();
    tempo = chrono::duration<double, milli>(fim - inicio).count();
    tamanho_caminho = caminho.size() - 1;
    grafo.exibirCaminho(caminho, 2);
}

void exibirComparacao(double tempo_bfs, size_t max_tamanho_fila, size_t tamanho_caminho_bfs, bool bfs_completo, double tempo_dfs, size_t max_tamanho_pilha, size_t tamanho_caminho_dfs, bool dfs_otimo, bool dfs_completo) {
    cout << "\n======================================== COMPARAÇÃO DOS RESULTADOS =========================================\n";
    cout << "Algoritmo\t| Tempo de Execução\t| Consumo de Memória\t| Arestas\t| Optimalidade\t| Completude\n";
    cout << "------------------------------------------------------------------------------------------------------------\n";
    cout << "BFS\t\t| " << tempo_bfs << "ms\t\t| " << max_tamanho_fila << " elementos\t\t| " << tamanho_caminho_bfs << "\t\t| Ótimo\t\t| ";
    cout << (bfs_completo ? "Sim\n" : "Não\n");
    cout << "DFS\t\t| " << tempo_dfs << "ms\t\t| " << max_tamanho_pilha << " elementos\t\t| " << tamanho_caminho_dfs << "\t\t| ";
    cout << (dfs_otimo ? "Ótimo\t\t| " : "Não Ótimo\t| ");
    cout << (dfs_completo ? "Sim\n" : "Não\n");
    cout << "============================================================================================================\n";
}
