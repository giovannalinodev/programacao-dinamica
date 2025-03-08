// troco_memo.cpp
// Implementação recursiva do problema do troco com memoization.
// Para compilar: g++ -std=c++11 problema-troco-memo.cpp -o problema-troco-memo
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int trocoMemo(const vector<int>& moedas, int V, vector<int>& memo) {
    if(V == 0) return 0;
    if(V < 0) return INT_MAX;
    if(memo[V] != -1) return memo[V];
    
    int minMoedas = INT_MAX;
    for (int c : moedas) {
        int res = trocoMemo(moedas, V - c, memo);
        if(res != INT_MAX)
            minMoedas = min(minMoedas, res + 1);
    }
    memo[V] = minMoedas;
    return memo[V];
}

int main(){
    vector<int> moedas = {1, 3, 5};
    int V = 13;
    vector<int> memo(V+1, -1);
    int resultado = trocoMemo(moedas, V, memo);
    if(resultado == INT_MAX)
        cout << "Troco impossível." << endl;
    else
        cout << "Mínimo número de moedas (Memoization): " << resultado << endl;
    return 0;
}
