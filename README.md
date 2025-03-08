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

### 📌 **1. Problema do Troco**
- Objetivo: Determinar a quantidade mínima de moedas necessárias para formar um valor `V`, utilizando um conjunto de moedas `C = {c1, c2, ..., cn}`.
- Métodos Implementados:
  - **Guloso**
  - **Recursivo**
  - **Memoization**
  - **Programação Dinâmica**
- Código-fonte em: `/problema-troco/`

### 📌 **2. Problema do Abastecimento de Combustível**
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

### 📌 **3. Problema da Loja de Livros**
- Objetivo: Dado um conjunto de livros com preços e quantidade de páginas, determinar **o maior número de páginas possível** que um cliente pode comprar com um orçamento fixo.
- Métodos Implementados:
  - **Backtracking**
  - **Programação Dinâmica**
- Código-fonte em: `/problema-loja-livros/`

### 📌 **4. Problema da Contagem de Moedas**
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
