#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
}