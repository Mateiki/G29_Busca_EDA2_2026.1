#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILMES 101606 //Quantidade de filmes
#define TAM_BUFFER 256

int main() {
    FILE *dataset = fopen("../../data/movies_name.txt", "r");

    if (dataset == NULL) {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

    char *lista[MAX_FILMES];
    char buffer[TAM_BUFFER];

    int i = 0;

    while (fgets(buffer, TAM_BUFFER, dataset) != NULL && i < MAX_FILMES) {
        // remover \n
        buffer[strcspn(buffer, "\n")] = '\0';

        // armazena em tamanho a quantidade de caracteres do nome do filme
        int tamanho = strlen(buffer);

        // alocar memória exata (+1 por causa do \0)
        lista[i] = (char *) malloc((tamanho + 1) * sizeof(char));

        // copiar string para memória alocada
        strcpy(lista[i], buffer);

        i++;
    }

    fclose(dataset);

    int total_filmes = i;

    //Busca Sequencial:
        char busca[100];

    printf("Digite o nome do filme: ");
    fgets(busca, 100, stdin);

    // remover \n da entrada do usuário
    busca[strcspn(busca, "\n")] = '\0';

    int encontrado = 0;

    //Início da medição de tempo
    clock_t inicio, fim;
    inicio = clock();

    for (int j = 0; j < total_filmes; j++) {
        if (strcmp(lista[j], busca) == 0) {
            printf("Filme encontrado na posicao %d\n", j);
            encontrado = 1;
            break;
        }
    }

    fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    if (!encontrado) {
        printf("Filme nao encontrado\n");
    }

    printf("Tempo gasto: %f segundos\n", tempo);

    // Liberar memória
    for (int j = 0; j < total_filmes; j++) {
        free(lista[j]);
    }

    return 0;
}