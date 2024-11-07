#include "Grafo.hpp"

Grafo::Grafo(){
    ifstream file("./dataset/grafo.txt");
     if(!file.is_open()){
        cerr << "\nErro ao abrir o arquivo grafo.txt\n" << endl;
        exit(1);
    }
    string linha;
    if (getline(file, linha)) {
        istringstream iss(linha);
        char vertice;
        while (iss >> vertice) {
            adicionarVertice(vertice);
        }
    }
    while (getline(file, linha)) {
        istringstream iss(linha);
        char origem, destino;
        if (iss >> origem >> destino) {
            adicionarAresta(origem, destino);
        }
    }
    file.close();
}

void Grafo::adicionarVertice(char vertice){
    if (this->adjacencias.find(vertice) == this->adjacencias.end()){
        this->adjacencias[vertice] = vector<char>();
    }
}

void Grafo::adicionarAresta(char origem, char destino){
    adicionarVertice(origem);
    adicionarVertice(destino);
    this->adjacencias[origem].push_back(destino);
    this->adjacencias[destino].push_back(origem);

}

void Grafo::exibirGrafo(){
    for (const auto& par : this->adjacencias){
        cout << par.first << ": ";
        for (char vizinho : par.second){
            cout << vizinho << " ";
        }
        cout << endl;
    }
}


vector<char> Grafo::bfs(char inicio, char objetivo) {
    unordered_map<char, bool> visitado;
    unordered_map<char, char> predecessor;
    queue<char> fila;
    visitado[inicio] = true;
    fila.push(inicio);
    while (!fila.empty()) {
        char atual = fila.front();
        fila.pop();
        if (atual == objetivo) {
            vector<char> caminho;
            for (char v = objetivo; v != inicio; v = predecessor[v]) {
                caminho.push_back(v);
            }
            caminho.push_back(inicio);
            reverse(caminho.begin(), caminho.end());
            return caminho;
        }
        for (char vizinho : this->adjacencias[atual]) {
            if (!visitado[vizinho]) {
                visitado[vizinho] = true;
                predecessor[vizinho] = atual;
                fila.push(vizinho);
            }
        }
    }
    return {};
}

vector<char> Grafo::dfs(char inicio, char objetivo) {
    stack<char> pilha;
    unordered_set<char> visitados;
    vector<char> caminho;
    pilha.push(inicio);
    while (!pilha.empty()) {
        char atual = pilha.top();
        pilha.pop();
        if (atual == objetivo) {
            caminho.push_back(atual);
            return caminho;
        }
        if (visitados.find(atual) == visitados.end()) {
            caminho.push_back(atual);
            visitados.insert(atual);
            for (auto vizinho : adjacencias[atual]) {
                if (visitados.find(vizinho) == visitados.end()) {
                    pilha.push(vizinho);
                }
            }
        }
    }
    return {}; 
}

void Grafo::exibirCaminho(const vector<char>& caminho, int busca) {
    if (caminho.empty()) {
        cout << "Objetivo não encontrado." << endl;
    } else {
        switch (busca){
            case 1:
                cout << "\nCaminho percorrido no BFS: ";
                break;
            case 2:
                cout << "\nCaminho percorrido no DFS: ";
                break;
            default:
                break;
        }
        for (char v : caminho) {
            cout << v << " ";
        }
        cout << "\n";
    }
}
    
