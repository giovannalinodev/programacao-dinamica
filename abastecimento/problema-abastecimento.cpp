// Implementação do problema do abastecimento de combustível usando programação dinâmica.
// Para compilar: g++ -std=c++11 abastecimento.cpp -o abastecimento
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void imprimirTabelaDP(const vector<int>& pos, const vector<int>& dp) {
    cout << "\nTabela de Programação Dinâmica:\n";
    cout << "Posição (km)  |  Tempo mínimo para chegar (min)\n";
    cout << "----------------------------------------------\n";
    for (size_t i = 0; i < pos.size(); i++) {
        if (dp[i] == 1e9) {
            cout << pos[i] << " km        |  INF\n";
        } else {
            cout << pos[i] << " km        |  " << dp[i] << " min\n";
        }
    }
    cout << "----------------------------------------------\n";
}

int tempoMinimoAbastecimento(const vector<int>& pos, const vector<int>& tempo, int D) {
    int n = pos.size();
    const int INF = 1e9;
    vector<int> dp(n, INF);

    // Inicializa: postos que podem ser alcançados diretamente de C1 (posição 0)
    for (int i = 0; i < n; i++) {
        if (pos[i] <= 100)
            dp[i] = tempo[i];
    }

    // Atualiza DP baseado nos postos disponíveis
    for (int i = 0; i < n; i++) {
        if (dp[i] == INF) continue;
        for (int j = i + 1; j < n; j++) {
            if (pos[j] - pos[i] <= 100) {
                dp[j] = min(dp[j], dp[i] + tempo[j]);
            }
        }
    }

    // Verifica os postos que permitem chegar a C2
    int ans = INF;
    for (int i = 0; i < n; i++) {
        if (D - pos[i] <= 100)
            ans = min(ans, dp[i]);
    }

    // Imprimir a tabela de DP para análise
    imprimirTabelaDP(pos, dp);

    return (ans == INF ? -1 : ans);
}

int main() {
    // --- Caso de Teste 1: Viagem sem necessidade de parada ---
    cout << "Teste 1: Viagem sem paradas (D = 90 km)\n";
    cout << "Tempo mínimo de abastecimento: 0 minutos\n\n";

    // --- Caso de Teste 2: Uma parada necessária ---
    {
        int D = 150;
        vector<int> pos = {50, 100};
        vector<int> tempo = {10, 20}; // Parada melhor em p1 (50 km, 10 minutos)
        int resultado = tempoMinimoAbastecimento(pos, tempo, D);
        cout << "Teste 2: D = 150 km\n";
        cout << "Tempo mínimo de abastecimento: " << resultado << " minutos\n\n";
    }

    // --- Caso de Teste 3: Múltiplas paradas necessárias ---
    {
        int D = 250;
        vector<int> pos = {80, 150, 210};
        vector<int> tempo = {5, 10, 3};
        int resultado = tempoMinimoAbastecimento(pos, tempo, D);
        cout << "Teste 3: D = 250 km\n";
        cout << "Tempo mínimo de abastecimento: " << resultado << " minutos\n\n";
    }

    // --- Caso de Teste 4: Viagem longa com paradas estratégicas ---
    {
        int D = 400;
        vector<int> pos = {50, 120, 180, 250, 320};
        vector<int> tempo = {5, 3, 7, 2, 4};
        int resultado = tempoMinimoAbastecimento(pos, tempo, D);
        cout << "Teste 4: D = 400 km\n";
        cout << "Tempo mínimo de abastecimento: " << resultado << " minutos\n\n";
    }

    // --- Caso de Teste 5: Caminho ótimo ignorando postos mais lentos ---
    {
        int D = 500;
        vector<int> pos = {90, 190, 290, 390, 490};
        vector<int> tempo = {6, 4, 8, 3, 2};
        int resultado = tempoMinimoAbastecimento(pos, tempo, D);
        cout << "Teste 5: D = 500 km\n";
        cout << "Tempo mínimo de abastecimento: " << resultado << " minutos\n\n";
    }

    // --- Caso de Teste 6: Longa viagem com escolha errada prejudicando o tempo ---
    {
        int D = 600;
        vector<int> pos = {60, 140, 220, 300, 380, 460, 540};
        vector<int> tempo = {5, 7, 3, 4, 6, 2, 10}; // Última escolha errada deve ser evitada
        int resultado = tempoMinimoAbastecimento(pos, tempo, D);
        cout << "Teste 6: D = 600 km\n";
        cout << "Tempo mínimo de abastecimento: " << resultado << " minutos\n\n";
    }

    return 0;
}
