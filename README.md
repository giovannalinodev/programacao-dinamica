# 📚 Trabalho de Programação Dinâmica - Algoritmos

Este repositório contém a implementação de problemas resolvidos utilizando **Programação Dinâmica (DP)**. 

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

## 🔍 **Problemas Resolvidos**

## 📌 **1. Problema do Troco**
- Objetivo: Determinar a quantidade mínima de moedas necessárias para formar um valor `V`, utilizando um conjunto de moedas `C = {c1, c2, ..., cn}`.
- Métodos Implementados:
  - **Guloso**
  - **Recursivo**
  - **Memoization**
  - **Programação Dinâmica**
- Código-fonte em: `/problema-troco/`

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

📌 **Conclusão**
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

## 🏗️ **Exemplo para compilar e executar**
1. **Compilar um arquivo específico:**
   ```bash
   g++ -std=c++11 problema-abastecimento/problema-abastecimento.cpp -o abastecimento


