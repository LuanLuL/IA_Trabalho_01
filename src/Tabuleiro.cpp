#include "Tabuleiro.hpp"

Tabuleiro::Tabuleiro(int tamanho) {
    this->TAMANHO = tamanho;
    this->barreiras = (bool****) malloc(this->TAMANHO * sizeof(bool***));
    for (int i = 0; i < this->TAMANHO; i++) {
        this->barreiras[i] = (bool***)malloc(this->TAMANHO * sizeof(bool**));
        for (int j = 0; j < this->TAMANHO; j++) {
            this->barreiras[i][j] = (bool**)malloc(this->TAMANHO * sizeof(bool*));
            for (int k = 0; k < this->TAMANHO; k++) {
                this->barreiras[i][j][k] = (bool*)malloc(this->TAMANHO * sizeof(bool));
                for (int l = 0; l < this->TAMANHO; l++) {
                    this->barreiras[i][j][k][l] = false;
                }
            }
        }
    }
    carregarBarreiras();
}

Tabuleiro::~Tabuleiro() {
    for (int i = 0; i < this->TAMANHO; ++i) {
        for (int j = 0; j < this->TAMANHO; ++j) {
            for (int k = 0; k < this->TAMANHO; ++k) {
                free(this->barreiras[i][j][k]);
            }
            free(this->barreiras[i][j]);
        }
        free(this->barreiras[i]);
    }
    free(this->barreiras);
}

bool Tabuleiro::getBarreira(int i, int j, int k, int l) {
    return this->barreiras[i][j][k][l];
}

Grafo Tabuleiro::getGrafo() {
    return this->grafo;
}

void Tabuleiro::carregarBarreiras() {
   ifstream file("./dataset/barreiras.txt");
    if(!file.is_open()){
        cerr << "\nErro ao abrir o arquivo barreiras.txt\n" << endl;
        exit(1);
    }
    string line;
    while (getline(file, line)) {
        int i1, j1, i2, j2;
        char ignore;
        istringstream ss(line);
        ss >> ignore >> i1 >> ignore >> j1 >> ignore >> ignore >> i2 >> ignore >> j2 >> ignore;
        barreiras[i1][j1][i2][j2] = true;
        barreiras[i2][j2][i1][j1] = true;
    }
    file.close();
}