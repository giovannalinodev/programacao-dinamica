// troco_dp.cpp
// Implementação do problema do troco usando programação dinâmica (bottom-up).
// Para compilar: g++ -std=c++11 problema-troco-dp.cpp -o problema-troco-dp
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int trocoDP(const vector<int>& moedas, int V) {
    vector<int> dp(V+1, INT_MAX);
    dp[0] = 0; // 0 moedas para formar o valor 0
    
    // Para cada valor de 1 até V, tenta-se usar cada moeda
    for (int v = 1; v <= V; v++) {
        for (int c : moedas) {
            if (v - c >= 0 && dp[v - c] != INT_MAX) {
                dp[v] = min(dp[v], dp[v-c] + 1);
            }
        }
    }
    return dp[V];
}

int main(){
    vector<int> moedas = {1, 3, 5};
    int V = 13;
    int resultado = trocoDP(moedas, V);
    if(resultado == INT_MAX)
        cout << "Troco impossível." << endl;
    else
        cout << "Mínimo número de moedas (DP): " << resultado << endl;
    return 0;
}
