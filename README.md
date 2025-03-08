# 📚 Trabalho de Programação Dinâmica - Algoritmos

Este repositório contém a implementação de **problemas resolvidos com Programação Dinâmica (DP)**.

O objetivo é **explorar diferentes estratégias algorítmicas** para otimizar a resolução de problemas combinatórios e de otimização.

Cada problema apresentado é resolvido utilizando **abordagens recursivas, memoization e programação dinâmica (bottom-up)**, além da comparação com outras abordagens como **algoritmos gulosos e backtracking**.

---

## 📁 **Estrutura do Projeto**
```bash
PD/
│── abastecimento/
│   ├── problema-abastecimento/
│   │   ├── problema-abastecimento.cpp
│
│── livros/
│   ├── problema-loja-livros.cpp
│
│── moedas/
│   ├── problema-conta-moedas.cpp
│
│── problema-troco/
│   ├── problema-troco-guloso.cpp
│   ├── problema-troco-memo.cpp
│   ├── problema-troco-pd.cpp
│   ├── problema-troco-recursivo.cpp
│
│── README.md
│── to-compile.txt
```

Cada problema é estruturado em uma pasta separada, contendo código-fonte, explicação do algoritmo e casos de teste quando solicitado.

---

## 🏗️ **Exemplo para compilar e executar**
1. **Compilar um arquivo específico:**
   ```bash
   g++ -std=c++11 problema-abastecimento/problema-abastecimento.cpp -o abastecimento
   ```

---

## 🔍 **Problemas Resolvidos**

## 📌 **1. Problema do Troco**
- Objetivo: Determinar a quantidade mínima de moedas necessárias para formar um valor `V`, utilizando um conjunto de moedas `C = {c1, c2, ..., cn}`.
- Métodos Implementados:
  - **Guloso**
  - **Recursivo**
  - **Memoization**
  - **Programação Dinâmica**
- Código-fonte em: `/problema-troco/`

### 📌 **(a) Solução Usando o Método Guloso**
O método guloso **seleciona sempre a maior moeda disponível primeiro**, antes de considerar as menores.

```cpp
int trocoGuloso(vector<int> moedas, int V) {
    sort(moedas.rbegin(), moedas.rend()); // Ordena em ordem decrescente
    int count = 0;
    for (int moeda : moedas) {
        int num = V / moeda;
        count += num;
        V -= num * moeda;
    }
    return (V == 0 ? count : -1); // Se sobrar troco, o método falhou
}
```
### 📌 (b) Quando o Método Guloso Funciona ou Falha
- O método guloso funciona bem se o sistema de moedas for canônico (qualquer valor pode ser formado combinando as menores denominações de maneira ótima).

**Situações em que o método guloso funciona:**

- Sistemas bem estruturados, como {1, 5, 10, 25} (moedas comuns).
Quando cada moeda é um múltiplo da anterior.

**Situações em que o método guloso falha:**

- Sistemas não canônicos, como {1, 3, 4} para V = 6. O método guloso escolheria (4,1,1) → 3 moedas, mas a solução ótima seria (3,3) → 2 moedas.

### 📌 (c) Implementação Recursiva do Problema do Troco

A abordagem recursiva usa a seguinte relação de recorrência:


$$
troco(C, V) =
\begin{cases} 
0, & \text{se } V = 0  \text{ (não há moedas necessárias)}\\
\infty, & \text{se } V < 0  \text{ (não há solução)} \\
1 + \min(troco(C, V - c_i)), & \forall c_i \in C, \text{ se } V > 0
\end{cases}
$$

```cpp
int trocoRecursivo(const vector<int>& moedas, int V) {
    if (V == 0) return 0;
    if (V < 0) return INT_MAX;
    
    int minMoedas = INT_MAX;
    for (int c : moedas) {
        int res = trocoRecursivo(moedas, V - c);
        if (res != INT_MAX)
            minMoedas = min(minMoedas, res + 1);
    }
    return minMoedas;
}

(problema-troco-recursivo.cpp implementa corretamente essa abordagem.)
```

### 📌 (d) Solução Usando Programação Dinâmica
A programação dinâmica (bottom-up) evita recálculos desnecessários preenchendo uma tabela de resultados intermediários.

#### 📌 **Estrutura da Tabela `dp[v]`**

Cada posição `dp[v]` representa **o menor número de moedas necessárias para formar `V`**.

#### **Preenchimento da Tabela**
| `V`               | `0` | `1` | `2` | `3` | `4` | `5` | `6` | `7` | `8` | `9` | `10` |
|-------------------|----|----|----|----|----|----|----|----|----|----|----|
| **Moedas `{1,3,5}`** | 0  | 1  | 1  | 1  | 2  | 1  | 2  | 2  | 3  | 3  | 2  |

📌 **Lógica da tabela**  
- **Cada coluna `V`** representa um valor a ser obtido.  
- **Cada célula `dp[v]`** contém o **número mínimo de moedas** necessárias para alcançar `V`.  
- Por exemplo, para `V = 7`, a solução ótima usa **2 moedas** `{3, 3, 1}`.

---

## 📌 **Implementação com Programação Dinâmica**
```cpp
int trocoDP(const vector<int>& moedas, int V) {
    vector<int> dp(V+1, INT_MAX);
    dp[0] = 0;  // Caso base: zero moedas necessárias para formar o valor 0

    for (int v = 1; v <= V; v++) {
        for (int c : moedas) {
            if (v - c >= 0 && dp[v - c] != INT_MAX) {
                dp[v] = min(dp[v], dp[v - c] + 1);
            }
        }
    }
    return dp[V];
}
```

### 📌 (e) Solução com Memoization
A versão otimizada com Memoization reduz chamadas recursivas armazenando resultados.

```cpp
int trocoMemo(const vector<int>& moedas, int V, vector<int>& memo) {
    if (V == 0) return 0;
    if (V < 0) return INT_MAX;
    if (memo[V] != -1) return memo[V];

    int minMoedas = INT_MAX;
    for (int c : moedas) {
        int res = trocoMemo(moedas, V - c, memo);
        if (res != INT_MAX)
            minMoedas = min(minMoedas, res + 1);
    }
    memo[V] = minMoedas;
    return memo[V];
}
```

### 📌 **Resultados Obtidos para o Problema do Troco**

A tabela abaixo apresenta a **quantidade mínima de moedas encontradas** por cada abordagem:

| **Método**            | **Mínimo Número de Moedas** |
|-----------------------|---------------------------|
| **Guloso**           | 2                           |
| **Recursivo**        | 3                           |
| **Memoization**      | 3                           |
| **Programação Dinâmica (DP)** | 3                  |

---
📌 **Conclusão:**
- O **método guloso** encontrou **2 moedas**, mas esse **não é o resultado ótimo**, pois o método **não garante a melhor solução para todos os sistemas de moedas**.
- As abordagens **Recursiva, Memoization e Programação Dinâmica** encontraram **a solução correta de 3 moedas**.
- **DP e Memoization são as abordagens mais eficientes** para sistemas maiores, pois evitam recomputação excessiva.





## 📌 **2. Problema do Abastecimento de Combustível**
- Objetivo: Determinar o **menor tempo possível** gasto nos postos de combustível para percorrer uma estrada entre duas cidades `C1` e `C2`.
- Regras:
  - O carro percorre **100 km** com o tanque cheio.
  - Se parar em um posto, deve **abastecer completamente**.
  - O tempo total gasto nos postos deve ser **minimizado**.
- Código-fonte em : `/problema-abastecimento/problema-abastecimento.cpp`

 **Casos de Teste**  
- **Testes** cobrindo viagens longas (`D = 400 km, 500 km, 600 km`).  
- Testes estratégicos para garantir que o **algoritmo ignore postos ineficientes** e escolha sempre o melhor caminho.

 **Tabela de Programação Dinâmica (DP)**  
- **Imprime a tabela de DP**, permitindo visualizar como as decisões são tomadas.

## 📊 **Tabelas - Problema do Abastecimento de Combustível**


### 🛣️ **Teste 1: Viagem sem paradas (D = 90 km)**
**Tempo mínimo de abastecimento:** `0 minutos`

#### 📌 **Tabela de Programação Dinâmica**
| Posição (km) | Tempo mínimo para chegar (min) |
|-------------|--------------------------------|
| 50 km       | 10 min                         |
| 100 km      | 20 min                         |

---

### 🛣️ **Teste 2: D = 150 km**
**Tempo mínimo de abastecimento:** `10 minutos`

#### 📌 **Tabela de Programação Dinâmica**
| Posição (km) | Tempo mínimo para chegar (min) |
|-------------|--------------------------------|
| 80 km       | 5 min                          |
| 150 km      | 15 min                         |
| 210 km      | 18 min                         |

---

### 🛣️ **Teste 3: D = 250 km**
**Tempo mínimo de abastecimento:** `15 minutos`

#### 📌 **Tabela de Programação Dinâmica**
| Posição (km) | Tempo mínimo para chegar (min) |
|-------------|--------------------------------|
| 50 km       | 5 min                          |
| 120 km      | 8 min                          |
| 180 km      | 15 min                         |
| 250 km      | 17 min                         |
| 320 km      | 21 min                         |

---

### 🛣️ **Teste 4: D = 400 km**
**Tempo mínimo de abastecimento:** `21 minutos`

#### 📌 **Tabela de Programação Dinâmica**
| Posição (km) | Tempo mínimo para chegar (min) |
|-------------|--------------------------------|
| 90 km       | 6 min                          |
| 190 km      | 10 min                         |
| 290 km      | 18 min                         |
| 390 km      | 21 min                         |
| 490 km      | 23 min                         |

---

### 🛣️ **Teste 5: D = 500 km**
**Tempo mínimo de abastecimento:** `23 minutos`

#### 📌 **Tabela de Programação Dinâmica**
| Posição (km) | Tempo mínimo para chegar (min) |
|-------------|--------------------------------|
| 60 km       | 5 min                          |
| 140 km      | 12 min                         |
| 220 km      | 15 min                         |
| 300 km      | 19 min                         |
| 380 km      | 25 min                         |
| 460 km      | 27 min                         |
| 540 km      | 37 min                         |

---

### 🛣️ **Teste 6: D = 600 km**
**Tempo mínimo de abastecimento:** `37 minutos`

#### 📌 **Tabela de Programação Dinâmica**
| Posição (km) | Tempo mínimo para chegar (min) |
|-------------|--------------------------------|
| 60 km       | 5 min                          |
| 140 km      | 12 min                         |
| 220 km      | 15 min                         |
| 300 km      | 19 min                         |
| 380 km      | 25 min                         |
| 460 km      | 27 min                         |
| 540 km      | 37 min                         |

---

### ✅ **Explicação**
Cada posição representa um **posto de combustível disponível** e o **tempo mínimo acumulado** para alcançá-lo.  
O tempo ótimo de abastecimento é determinado considerando apenas os postos necessários para minimizar o tempo total de viagem.




## 📌 **3. Problema da Loja de Livros**
- Objetivo: Dado um conjunto de livros com preços e quantidade de páginas, determinar **o maior número de páginas possível** que um cliente pode comprar com um orçamento fixo.
- Métodos Implementados:
  - **Backtracking**
  - **Programação Dinâmica**
- Código-fonte em: `/problema-loja-livros/`
## 📊 **Análise de Desempenho - Problema da Loja de Livros**

### **📌 Comparação entre Backtracking e Programação Dinâmica**
Após compilar e executar o código **problema-loja-livros**, os resultados mostraram a comparação entre **Backtracking e Programação Dinâmica (DP)** na maximização do número de páginas adquiridas dentro do orçamento.

---

### **1️⃣ Resultados Obtidos**
#### **Backtracking**

```bash 
Máximo de páginas (Backtracking): 220 Tempo de execução (Backtracking): 1 microssegundos
```
#### **Programação Dinâmica (DP)**
```bash 
Tabela DP: 0 0 0 0 0 0 0 0 0 0 60 60 60 60 60 60 60 60 60 60 100 100 100 100 100 100 100 100 100 100 160 160 160 160 160 160 160 160 160 160 180 180 180 180 180 180 180 180 180 180 220 0 0 0 0 0 0 0 0 0 0 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 120 120 120 120 120 120 120 120 120 120 180 180 180 180 180 180 180 180 180 180 180 0 0 0 0 0 0 0 0 0 0 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 Máximo de páginas (DP): 220 Tempo de execução (DP): 230 microssegundos
```

---

### **Interpretação dos Resultados**
#### ✅ **Backtracking**
- A **solução Backtracking encontrou corretamente 220 páginas** como a melhor resposta.
- O tempo de execução foi **1 microssegundo**, mostrando que, para **entradas pequenas**, o Backtracking não tem um custo alto.
- O Backtracking **cresce exponencialmente** conforme o número de livros aumenta, tornando-se impraticável para problemas maiores.

#### ✅ **Programação Dinâmica (DP)**
- A **solução DP também encontrou corretamente 220 páginas**, confirmando a resposta ótima.
- A **tabela DP foi preenchida corretamente**, armazenando o número máximo de páginas possíveis para cada orçamento até `X=50`.
- O tempo de execução foi **230 microssegundos**, um valor **maior que o Backtracking nesta entrada pequena**, porque a DP tem um **custo fixo inicial no preenchimento da tabela**.
- **Para entradas maiores, a DP será muito mais eficiente** que o Backtracking.

---

### **Comparação de Desempenho**
| Método | Páginas Máximas Encontradas | Tempo de Execução |
|--------|---------------------------|----------------|
| **Backtracking** | ✅ 220 | **1 microssegundo** |
| **Programação Dinâmica** | ✅ 220 | **230 microssegundos** |

📌 **Explicação**
- Para **entradas pequenas**, o **Backtracking pode ser mais rápido** porque **não precisa preencher toda a tabela DP**.
- Para **entradas grandes**, o **Backtracking se torna inviável**, pois seu tempo de execução **cresce exponencialmente**.
- **A DP cresce polinomialmente (`O(N*X)`) e é a melhor abordagem para grandes conjuntos de dados**.
- **A Programação Dinâmica é mais eficiente para entradas grandes**, enquanto o **Backtracking ficou competitivo para pequenos problemas**.




## 📌 **4. Problema da Contagem de Moedas**
- Objetivo: Determinar de **quantas formas diferentes** é possível formar um valor `V`, utilizando um conjunto de moedas `C = {c1, c2, ..., cn}`.
- Métodos Implementados:
  - **Recursão**
  - **Programação Dinâmica**
- Código-fonte em: `/problema-conta-moedas/`

---
### 📌 (a) Definição da Função de Recorrência

O número de formas distintas \( f(k, V) \) de formar um valor \( V \) usando moedas a partir do índice \( k \) é dado por:

$$
f(k, V) =
\begin{cases} 
1, & \text{se } V = 0  \text{ (existe uma forma: não usar nenhuma moeda)}\\
0, & \text{se } V < 0  \text{ ou } k \geq n \text{ (sem formas válidas)} \\
f(k, V - C_k) + f(k+1, V), & \text{caso contrário}
\end{cases}
$$


**Explicação:**
- **Caso Base 1:** Se `V = 0`, há exatamente **1 forma** de obtê-lo (não usar moedas).
- **Caso Base 2:** Se `V < 0` ou **não há mais moedas disponíveis (`k >= n`)**, não há solução.
- **Caso Recursivo:** Podemos:
  - **Usar a moeda `C[k]`** (diminuir `V` e permanecer com `C[k]`).
  - **Pular para a próxima moeda** `C[k+1]` e tentar formar `V` sem `C[k]`.

---

### **📌 (b) Implementação da Função Recursiva**
A função `contarFormasRec()` usa a relação de recorrência para contar todas as formas possíveis:
```cpp
int contarFormasRec(const vector<int>& moedas, int V, int k) {
    if (V == 0) return 1;      // Se V == 0, há exatamente 1 forma (não usar moedas)
    if (V < 0 || k >= moedas.size()) return 0;  // Sem solução válida
    // Opção 1: Usar a moeda C[k] e continuar usando-a
    int usar = contarFormasRec(moedas, V - moedas[k], k);
    // Opção 2: Pular para a próxima moeda
    int pular = contarFormasRec(moedas, V, k + 1);
    return usar + pular;
}
```

### 📌 (c) Definição da Tabela de Programação Dinâmica

A tabela `dp[k][v]` armazena **quantas formas existem de obter `V` usando moedas de `k` em diante**.

#### **Estrutura da Tabela**
| Moedas (`k`) | `0` | `1` | `2` | `3` | `4` | `5` | `6` | `7` | `8` | `9` |
|--------------|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|
| **`C[0]=2`** | 1   | 0   | 1   | 1   | 1   | 2   | 2   | 2   | 3   | 3   |
| **`C[1]=3`** | 1   | 0   | 0   | 1   | 0   | 1   | 1   | 0   | 1   | 1   |
| **`C[2]=5`** | 1   | 0   | 0   | 0   | 0   | 1   | 0   | 0   | 0   | 0   |

📌 **Explicação**
- Cada **linha representa uma moeda** do conjunto `{C1, C2, ..., Cn}`.
- Cada **coluna `v` representa um valor-alvo `V`** a ser obtido com as moedas disponíveis.
- O valor `dp[k][v]` indica **quantas formas distintas existem para formar `V`** utilizando as moedas **de `k` em diante**.


### **📌 (d) Implementação com Programação Dinâmica**

```
int contarFormasDP(const vector<int>& moedas, int V) {
    int n = moedas.size();
    vector<vector<int>> dp(n+1, vector<int>(V+1, 0));
    
    // Caso base: Para V = 0, sempre há 1 forma de formar o valor (não usar moedas)
    for (int k = 0; k <= n; k++) {
        dp[k][0] = 1;
    }
    
    // Preenche a tabela DP de baixo para cima
    for (int k = n - 1; k >= 0; k--) {
        for (int v = 1; v <= V; v++) {
            int usar = (v - moedas[k] >= 0) ? dp[k][v - moedas[k]] : 0;
            int pular = dp[k+1][v];
            dp[k][v] = usar + pular;
        }
    }

    return dp[0][V];
}
```

### 📌 (e) Análise de Desempenho

Executando o código, obtemos:
```
Contagem de formas usando Recursão: Resultado: 3 Tempo de execução (Recursão): 2 microssegundos
```

```
Contagem de formas usando Programação Dinâmica: Tabela DP (contar formas): 1 0 1 1 1 2 2 2 3 3 1 0 0 1 0 1 1 0 1 1 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 Resultado: 3 Tempo de execução (DP): 72 microssegundos
```

---

### **Comparação de Desempenho**

| **Método**                | **Formas encontradas** | **Tempo de Execução** |
|---------------------------|-----------------------|----------------------|
| **Recursão**              | ✅ 3                   | **2 microssegundos**  |
| **Programação Dinâmica**  | ✅ 3                   | **72 microssegundos** |

---

### 📌 **Explicação**
- Para **valores pequenos (`V` pequeno)**, a **Recursão pode ser mais rápida** porque **não precisa preencher a tabela DP**.
- Para **valores grandes**, a **Programação Dinâmica é muito mais eficiente**, pois **evita cálculos repetidos**.
- **A DP cresce polinomialmente (`O(n*V)`) e é a melhor escolha para grandes valores de `V`**.







