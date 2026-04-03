# 🔍 Busca Sequencial em C

Este diretório contém a implementação de um algoritmo de **busca sequencial** em linguagem C, utilizando um dataset de nomes de filmes armazenados em arquivo `.txt`.

---

## 🧠 O que é Busca Sequencial?

A **busca sequencial** (ou linear) é o algoritmo mais simples de busca:

* Percorre os elementos **um a um**
* Compara cada elemento com o valor desejado
* Para quando encontra (ou chega ao final)

### 📌 Complexidade

* **Melhor caso:** O(1) → elemento na primeira posição
* **Caso médio:** O(n/2)
* **Pior caso:** O(n) → elemento no final ou inexistente

---

## 📂 Funcionamento do Código

### 1. 📥 Leitura do Dataset

O programa começa abrindo o arquivo:

```c
FILE *dataset = fopen("../../data/movies_name.txt", "r");
```

Depois:

* Lê linha por linha com `fgets`
* Remove o `\n`
* Aloca memória dinamicamente (`malloc`)
* Armazena cada nome em um vetor de strings (`char *lista[]`)

---

### 2. 🧱 Estrutura de Dados

```c
char *lista[MAX_FILMES];
```

Cada posição do vetor aponta para:

* uma string com tamanho exato
* contendo o nome de um filme

---

### 3. 🔎 Busca Sequencial

O usuário digita um nome:

```c
fgets(busca, 100, stdin);
```

O algoritmo então percorre toda a lista:

```c
for (int j = 0; j < total_filmes; j++) {
    int resultado = strcmp(lista[j], busca);
}
```

* `strcmp` compara duas strings
* Retorna `0` quando são iguais

---

### 4. ⏱️ Medição de Tempo

O tempo é medido com:

```c
clock_t inicio = clock();
...
clock_t fim = clock();
```

Para melhorar a precisão, a busca é repetida várias vezes:

```c
#define REPETICOES 1000
```

Isso permite calcular:

* tempo total
* tempo médio por busca

---

### 5. 📊 Contagem de Comparações

O código também mede quantas comparações foram feitas:

```c
long long comparacoes;
```

Isso é importante porque:

👉 A complexidade do algoritmo depende diretamente disso

---

### 6. ⚠️ Evitando otimizações do compilador

```c
volatile int dummy = 0;
```

Essa variável garante que o compilador não ignore o loop durante otimizações.

---

## 📈 Comportamento do Algoritmo

A busca sequencial depende **diretamente da posição do elemento**:

| Situação       | Comparações |
| -------------- | ----------- |
| Início         | poucas      |
| Meio           | médias      |
| Final          | muitas      |
| Não encontrado | máximas     |

---

## 📊 Base Ordenada vs Desordenada

### 🔹 Importante:

👉 A busca sequencial **NÃO depende da ordenação dos dados**

---

### 📂 Diferença no código

A única diferença entre os testes é o arquivo utilizado:

```c
// Base desordenada
FILE *dataset = fopen("../../data/movies_name.txt", "r");

// Base ordenada
FILE *dataset = fopen("../../data/movies_ordenado.txt", "r");
```

---

### ⚠️ Impacto na performance

A ordenação pode:

* ✔️ Melhorar o tempo → se o elemento estiver no início
* ❌ Piorar o tempo → se o elemento for deslocado para o final

---

### 🧠 Conclusão

👉 A ordenação **não melhora o algoritmo em si**

Ela apenas:

* muda a **posição do elemento**
* e isso afeta o número de comparações

---

## 🔬 Observações sobre os testes

* O tempo pode variar entre execuções (ruído do sistema)
* A métrica mais confiável é:

  * número de comparações
  * comportamento relativo

---

## 🚀 Possíveis melhorias

* Implementar **busca binária** (necessita dados ordenados)
* Comparar desempenho entre algoritmos
* Medir tempo com maior precisão
* Trabalhar com estruturas mais complexas (structs)

---

## 📌 Conclusão

A busca sequencial é:

* simples de implementar
* eficiente para conjuntos pequenos
* pouco eficiente para grandes volumes de dados

👉 Seu custo cresce linearmente com o tamanho da base (**O(n)**)
