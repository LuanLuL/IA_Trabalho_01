#include <iostream>
#include <locale>

#include "Tabuleiro.hpp"

using namespace std;

int main() {
    Tabuleiro tabuleiro(5);
    cout << "\n\nBarreira = " << tabuleiro.getBarreira(1, 2, 2, 2) << "\n\n\n";
    tabuleiro.getGrafo().exibirGrafo();
    return 0;
}
