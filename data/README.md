## 📂 Dataset

O conjunto de dados utilizado neste projeto foi obtido a partir do Kaggle:

🔗 https://www.kaggle.com/datasets/kurtnakasato/imdb-100000-moviestvshows

Este dataset contém informações sobre os **100.000 filmes e séries mais bem avaliados do IMDb**, incluindo diversos atributos como título, ano de lançamento, avaliação, entre outros.

---

## 🔧 Pré-processamento

Para adequação aos testes de algoritmos de busca, o dataset original (formato `.csv`) foi simplificado, mantendo apenas os nomes dos filmes.

### 📝 Conversão do CSV para TXT

A conversão foi realizada de forma manual, seguindo os passos:

1. Abertura do arquivo `.csv` em uma ferramenta de planilha (Excel, LibreOffice ou similar)
2. Seleção da coluna correspondente aos **nomes dos filmes** (segunda coluna do dataset)
3. Cópia dos dados selecionados
4. Colagem em um novo arquivo de texto (`.txt`)
5. Salvamento do arquivo como:

```
movies_name.txt
```

O arquivo resultante contém **um nome de filme por linha**, facilitando a leitura e processamento em linguagem C.

---

## 🔡 Ordenação dos dados

Para viabilizar a utilização de algoritmos como a **Busca Binária**, foi necessário criar uma versão ordenada do dataset.

A ordenação foi realizada utilizando o comando abaixo no terminal Linux:

```
sort --ignore-case movies_name.txt > movies_ordenado.txt
```

### 📌 Detalhes da ordenação:

* `sort`: realiza a ordenação dos dados
* `--ignore-case`: ignora diferenças entre letras maiúsculas e minúsculas
* `>`: redireciona a saída para um novo arquivo

O arquivo gerado:

```
movies_ordenado.txt
```

é utilizado especificamente nos testes de algoritmos que requerem dados ordenados.


