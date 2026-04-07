# Bench Metodos de Busca

LINK DO VÍDEO: https://youtu.be/oTGsRp0r5u0

Número da Lista: 29<br>
Conteúdo da Disciplina: Buscas<br>

## Alunos
|Matrícula | Aluno |
| 241025327 |  Matheus Eiki Kimura |

## Sobre 
O Objetivo deste projeto era implementar diferentes tipos de buscas para aprendizado e realizar a comparação de desempenho entre os diferentes metodos sobre uma base de dados de mais de 100.000 filmes

## Screenshots
<img width="1916" height="1040" alt="image" src="https://github.com/user-attachments/assets/9beae618-1901-410d-8432-716689536126" />
<img width="1919" height="1040" alt="image" src="https://github.com/user-attachments/assets/68e88fdd-1c4e-43bd-b974-fa7c1842870b" />
<img width="1920" height="1038" alt="image" src="https://github.com/user-attachments/assets/3439cafc-6ab0-4fe9-8a88-59addd23b306" />



## Instalação 
Linguagem: C<br>
Caso o usuário queira testar a compilação é necessário o GCC (Compilador de C), Caso contrário já tem arquivos compilados prontos para serem executados

## Uso 
O usuário deve se direcionar a pasta 'scr' e depois ir para o diretório da busca que queira testar, utilizando o comando cd [diretório]. Após isso basta executar o código com './[nome do arquivo]' e colocar o nome do filme que queira testar!

## Outros 
🔎 Algoritmos implementados
🔹 Busca Sequencial
🔹 Busca Sequencial Indexada
🔹 Busca Binária

Cada algoritmo foi implementado de forma independente para facilitar o entendimento e comparação.

📁 Estrutura do Projeto
/buscas
    busca_sequencial.c
    busca_indexada.c
    busca_binaria.c

/dados
    pequeno.txt
    medio.txt
    grande.txt

/utils
    leitura_arquivo.c
    gerador_dados.c
📄 Base de Dados

Os dados utilizados no projeto são armazenados em arquivos .txt, contendo uma lista de elementos (ex: nomes de filmes), com um item por linha.

Exemplo (pequeno.txt):
Avatar
Batman
Interestelar
Matrix
Titanic
⚙️ Como os dados são utilizados

Os arquivos .txt são lidos e armazenados em estruturas de dados (vetores) na memória durante a execução do programa.

Exemplo de fluxo:

Leitura do arquivo
Armazenamento em vetor
Execução do algoritmo de busca
Contagem do número de comparações
📊 Medição de desempenho

A análise de desempenho é feita com base em:

✅ Número de comparações realizadas

Cada algoritmo possui uma variável do tipo:

long long comparacoes;

Essa abordagem foi escolhida por ser mais precisa que o tempo de execução, pois:

independe do hardware
evita variações do sistema operacional
permite comparação justa entre algoritmos
