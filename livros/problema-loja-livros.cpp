// loja_livros.cpp
// Problema da loja de livros: maximizar o número de páginas adquiridas com um orçamento fixo.
// Para compilar: g++ -std=c++11 loja_livros.cpp -o loja_livros
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Solução usando backtracking
int maxPaginasBacktracking(int i, int orcamento, const vector<int>& preco, const vector<int>& paginas) {
    if(i == preco.size() || orcamento == 0)
        return 0;
    // Opção de não comprar o livro i
    int semComprar = maxPaginasBacktracking(i + 1, orcamento, preco, paginas);
    int comprando = 0;
    if(orcamento >= preco[i])
        comprando = paginas[i] + maxPaginasBacktracking(i + 1, orcamento - preco[i], preco, paginas);
    return max(semComprar, comprando);
}

// Solução usando programação dinâmica (tabulação)
int maxPaginasDP(const vector<int>& preco, const vector<int>& paginas, int X) {
    int N = preco.size();
    // dp[i][j]: máximo de páginas adquiridas usando livros de i a N-1 com orçamento j
    vector<vector<int>> dp(N+1, vector<int>(X+1, 0));
    
    // Preenche a tabela de forma iterativa (caso base: dp[N][j] = 0)
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j <= X; j++) {
            if(j < preco[i])
                dp[i][j] = dp[i+1][j];
            else
                dp[i][j] = max(dp[i+1][j], paginas[i] + dp[i+1][j - preco[i]]);
        }
    }
    
    // Impressão da tabela para visualização
    cout << "Tabela DP:" << endl;
    for (int i = 0; i <= N; i++){
        for (int j = 0; j <= X; j++){
            cout << dp[i][j] << "\t";
        }
        cout << "\n";
    }
    
    return dp[0][X];
}

int main(){
    // Exemplo com 3 livros:
    // Livro 1: preço = 20, páginas = 100
    // Livro 2: preço = 30, páginas = 120
    // Livro 3: preço = 10, páginas = 60
    vector<int> preco = {20, 30, 10};
    vector<int> paginas = {100, 120, 60};
    int X = 50; // Orçamento
    
    cout << "Resolução com Backtracking:" << endl;
    int paginasMaxBT = maxPaginasBacktracking(0, X, preco, paginas);
    cout << "Máximo de páginas (Backtracking): " << paginasMaxBT << endl << endl;
    
    cout << "Resolução com Programação Dinâmica:" << endl;
    int paginasMaxDP = maxPaginasDP(preco, paginas, X);
    cout << "Máximo de páginas (DP): " << paginasMaxDP << endl;
    
    return 0;
}
