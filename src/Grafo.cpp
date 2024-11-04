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
