// troco_recursivo.cpp
// Implementação recursiva do problema do troco (sem memoization).
// Para compilar: g++ -std=c++11 troco_recursivo.cpp -o troco_recursivo
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int trocoRecursivo(const vector<int>& moedas, int V) {
    if(V == 0) return 0;
    if(V < 0) return INT_MAX; // Representa "infinito"
    
    int minMoedas = INT_MAX;
    for (int c : moedas) {
        int res = trocoRecursivo(moedas, V - c);
        if (res != INT_MAX) { // Somente se for possível obter o troco
            minMoedas = min(minMoedas, res + 1);
        }
    }
    return minMoedas;
}

int main(){
    vector<int> moedas = {1, 3, 5};
    int V = 13;
    int resultado = trocoRecursivo(moedas, V);
    if(resultado == INT_MAX)
        cout << "Troco impossível." << endl;
    else
        cout << "Mínimo número de moedas (recursivo): " << resultado << endl;
    return 0;
}
