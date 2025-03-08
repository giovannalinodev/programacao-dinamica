// troco_guloso.cpp
// Implementação do problema do troco utilizando o método guloso.
// Para compilar: g++ -std=c++11 troco_guloso.cpp -o troco_guloso
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trocoGuloso(vector<int> moedas, int V) {
    // Ordena as moedas em ordem decrescente
    sort(moedas.rbegin(), moedas.rend());
    int count = 0;
    for (int moeda : moedas) {
        // Calcula quantas moedas do tipo atual podem ser utilizadas
        int num = V / moeda;
        count += num;
        V -= num * moeda;
    }
    // Se o valor restante for zero, retornamos o número total de moedas usadas
    return (V == 0 ? count : -1);
}

int main() {
    // Exemplo: sistema S = {1, 2, 5} para V = 7
    vector<int> moedas = {1, 2, 5};
    int V = 7;
    int resultado = trocoGuloso(moedas, V);
    if(resultado == -1)
        cout << "Troco impossível com o método guloso." << endl;
    else
        cout << "Mínimo número de moedas (método guloso): " << resultado << endl;
    return 0;
}
