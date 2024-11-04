#ifndef __TABULEIRO_HPP
#define __TABULEIRO_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Grafo.hpp"

using namespace std;

class Tabuleiro {
private:
    bool ****barreiras;
    int TAMANHO;
    Grafo grafo;
public:
    Tabuleiro(int tamanho);
    ~Tabuleiro();
    bool getBarreira(int i, int j, int k, int l);
    Grafo getGrafo();
    void carregarBarreiras();
};

#endif 
