// Problema das moedas: contar de quantas formas é possível obter um valor V usando um conjunto de moedas.
// Para compilar: g++ -std=c++11 problema-conta-moedas.cpp -o problema-conta-moedas
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono> // Biblioteca para medir tempo de execução
using namespace std;
using namespace std::chrono;

// Função recursiva para contar formas
// k: índice atual na lista de moedas
int contarFormasRec(const vector<int>& moedas, int V, int k) {
    if (V == 0) return 1;      // Se o valor for exatamente 0, há 1 forma (não usar nenhuma moeda)
    if (V < 0 || k >= moedas.size()) return 0;
    // Opção de usar a moeda k (mantendo o mesmo índice para permitir repetições)
    int usar = contarFormasRec(moedas, V - moedas[k], k);
    // Opção de pular para a próxima moeda
    int pular = contarFormasRec(moedas, V, k + 1);
    return usar + pular;
}

// Solução com programação dinâmica (tabulação)
int contarFormasDP(const vector<int>& moedas, int V) {
    int n = moedas.size();
    // dp[k][v]: número de formas de obter o valor v utilizando moedas[k...n-1]
    vector<vector<int>> dp(n + 1, vector<int>(V + 1, 0));
    
    // Caso base: dp[k][0] = 1 para todo k (valor 0 pode ser formado sem usar moedas)
    for (int k = 0; k <= n; k++) {
        dp[k][0] = 1;
    }
    
    // Preenche a tabela de baixo para cima
    for (int k = n - 1; k >= 0; k--) {
        for (int v = 1; v <= V; v++) {
            int usar = (v - moedas[k] >= 0) ? dp[k][v - moedas[k]] : 0;
            int pular = dp[k + 1][v];
            dp[k][v] = usar + pular;
        }
    }
    
    // Impressão opcional da tabela para visualização
    cout << "Tabela DP (contar formas):" << endl;
    for (int k = 0; k <= n; k++) {
        for (int v = 0; v <= V; v++) {
            cout << dp[k][v] << "\t";
        }
        cout << "\n";
    }
    
    return dp[0][V];
}

int main() {
    vector<int> moedas = {2, 3, 5};
    int V = 9;

    // Medição de tempo para a solução recursiva
    cout << "Contagem de formas usando Recursão:" << endl;
    auto startRec = high_resolution_clock::now();
    int resultadoRec = contarFormasRec(moedas, V, 0);
    auto stopRec = high_resolution_clock::now();
    auto durationRec = duration_cast<microseconds>(stopRec - startRec);
    cout << "Resultado: " << resultadoRec << endl;
    cout << "Tempo de execução (Recursão): " << durationRec.count() << " microssegundos" << endl << endl;

    // Medição de tempo para a solução com Programação Dinâmica
    cout << "Contagem de formas usando Programação Dinâmica:" << endl;
    auto startDP = high_resolution_clock::now();
    int resultadoDP = contarFormasDP(moedas, V);
    auto stopDP = high_resolution_clock::now();
    auto durationDP = duration_cast<microseconds>(stopDP - startDP);
    cout << "Resultado: " << resultadoDP << endl;
    cout << "Tempo de execução (DP): " << durationDP.count() << " microssegundos" << endl;

    return 0;
}
