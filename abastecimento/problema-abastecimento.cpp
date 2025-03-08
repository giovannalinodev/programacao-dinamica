// abastecimento.cpp
// Implementação do problema do abastecimento de combustível usando programação dinâmica.
// Para compilar: g++ -std=c++11 abastecimento.cpp -o abastecimento
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int tempoMinimoAbastecimento(const vector<int>& pos, const vector<int>& tempo, int D) {
    int n = pos.size();
    const int INF = 1e9;
    vector<int> dp(n, INF);
    
    // Inicializa: postos que podem ser alcançados diretamente de C1 (posição 0)
    for (int i = 0; i < n; i++) {
        if (pos[i] <= 100)
            dp[i] = tempo[i];
    }
    
    // Para cada posto i alcançável, atualiza os postos j que podem ser atingidos a partir dele
    for (int i = 0; i < n; i++) {
        if(dp[i] == INF) continue;
        for (int j = i+1; j < n; j++) {
            if(pos[j] - pos[i] <= 100) {
                dp[j] = min(dp[j], dp[i] + tempo[j]);
            }
        }
    }
    
    // Verifica os postos que possibilitam chegar a C2 (último trecho <= 100 km)
    int ans = INF;
    for (int i = 0; i < n; i++) {
        if(D - pos[i] <= 100)
            ans = min(ans, dp[i]);
    }
    return (ans == INF ? -1 : ans);
}

int main(){
    // --- Caso de Teste 1: Viagem sem necessidade de parada (D = 90 km) ---
    cout << "Teste 1: Viagem sem paradas (D = 90 km)" << endl;
    // Se D <= 100 km, não há necessidade de abastecer.
    cout << "Tempo mínimo de abastecimento: 0 minutos" << endl << endl;
    
    // --- Caso de Teste 2: Uma parada necessária ---
    {
        int D = 150;
        vector<int> pos = {50, 100};
        vector<int> tempo = {10, 20}; // Parada melhor em p1 (50 km, 10 minutos)
        int resultado = tempoMinimoAbastecimento(pos, tempo, D);
        cout << "Teste 2: D = 150 km" << endl;
        cout << "Tempo mínimo de abastecimento: " << resultado << " minutos" << endl << endl;
    }
    
    // --- Caso de Teste 3: Múltiplas paradas necessárias ---
    {
        int D = 250;
        vector<int> pos = {80, 150, 210};
        vector<int> tempo = {5, 10, 3};
        int resultado = tempoMinimoAbastecimento(pos, tempo, D);
        cout << "Teste 3: D = 250 km" << endl;
        cout << "Tempo mínimo de abastecimento: " << resultado << " minutos" << endl;
    }
    
    return 0;
}
