#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILMES 101606
#define TAM_BUFFER 256
#define REPETICOES 1000

int main() {
    FILE *dataset = fopen("../../data/movies_ordenado.txt", "r");

    if (dataset == NULL) {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

    char *lista[MAX_FILMES];
    char buffer[TAM_BUFFER];

    int i = 0;

    // Leitura do arquivo
    while (fgets(buffer, TAM_BUFFER, dataset) != NULL && i < MAX_FILMES) {
        buffer[strcspn(buffer, "\n")] = '\0';

        int tamanho = strlen(buffer);

        lista[i] = (char *) malloc((tamanho + 1) * sizeof(char));

        if (lista[i] == NULL) {
            printf("Erro de alocacao\n");
            return 1;
        }

        strcpy(lista[i], buffer);

        i++;
    }

    fclose(dataset);

    int total_filmes = i;

    // =========================
    // BUSCA SEQUENCIAL
    // =========================

    char busca[100];

    printf("Digite o nome do filme: ");
    fgets(busca, 100, stdin);
    busca[strcspn(busca, "\n")] = '\0';

    int encontrado = 0;
    int posicao = -1;

    long long comparacoes = 0;   // contador de comparações
    volatile int dummy = 0;      // evita otimização do compilador

    clock_t inicio, fim;

    inicio = clock();

    for (int k = 0; k < REPETICOES; k++) {
        for (int j = 0; j < total_filmes; j++) {

            comparacoes++; // conta comparações

            int resultado = strcmp(lista[j], busca);
            dummy += resultado;  // impede otimização

            // só na primeira execução usa o resultado real
            if (k == 0 && resultado == 0) {
                encontrado = 1;
                posicao = j;
            }
        }
    }

    fim = clock();

    double tempo_total = (double)(fim - inicio) / CLOCKS_PER_SEC;
    double tempo_medio = tempo_total / REPETICOES;

    // Resultado da busca
    if (encontrado) {
        printf("Filme encontrado na posicao %d\n", posicao);
    } else {
        printf("Filme nao encontrado\n");
    }

    // Tempo
    printf("Tempo total (%d buscas): %f segundos\n", REPETICOES, tempo_total);
    printf("Tempo medio por busca: %f segundos\n", tempo_medio);

    // Estatística real
    printf("Total de comparacoes: %lld\n", comparacoes);
    printf("Media de comparacoes por busca: %lld\n", comparacoes / REPETICOES);

    // Liberar memória
    for (int j = 0; j < total_filmes; j++) {
        free(lista[j]);
    }

    return 0;
}