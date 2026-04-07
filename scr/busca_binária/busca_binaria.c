#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 110000   // um pouco maior que 100606
#define TAM_NOME 200
#define REPETICOES 1000

typedef struct {
    char nome[TAM_NOME];
} Filme;

Filme *filmes;
int total = 0;

// ==============================
// Função de comparação (qsort)
// ==============================
int comparar(const void *a, const void *b) {
    return strcmp(((Filme*)a)->nome, ((Filme*)b)->nome);
}

// ==============================
// Busca Binária
// ==============================
int buscaBinaria(char *chave, long long *comparacoes) {
    int inicio = 0;
    int fim = total - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        (*comparacoes)++;
        int cmp = strcmp(chave, filmes[meio].nome);

        if (cmp == 0) {
            return meio;
        }

        (*comparacoes)++;
        if (cmp < 0) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    return -1;
}

// ==============================
// Leitura do arquivo
// ==============================
void carregarArquivo() {
    FILE *arq = fopen("../../data/movies_ordenado.txt", "r");

    if (!arq) {
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }

    while (fgets(filmes[total].nome, TAM_NOME, arq) && total < MAX) {
        filmes[total].nome[strcspn(filmes[total].nome, "\n")] = '\0';
        total++;
    }

    fclose(arq);
}

// ==============================
// MAIN
// ==============================
int main() {
    filmes = malloc(MAX * sizeof(Filme));
    if (filmes == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    carregarArquivo();

    if (total == 0) {
        printf("Arquivo vazio.\n");
        free(filmes);
        return 1;
    }

    //Ordena o arquivo
    qsort(filmes, total, sizeof(Filme), comparar);

    char chave[TAM_NOME];
    printf("Digite o nome do filme: ");
    fgets(chave, TAM_NOME, stdin);
    chave[strcspn(chave, "\n")] = '\0';

    long long totalComparacoes = 0;

    for (int i = 0; i < REPETICOES; i++) {
        long long comparacoes = 0;
        buscaBinaria(chave, &comparacoes);
        totalComparacoes += comparacoes;
    }

    double media = (double) totalComparacoes / REPETICOES;

    printf("Media de comparacoes: %.2f\n", media);

    free(filmes);

    return 0;
}