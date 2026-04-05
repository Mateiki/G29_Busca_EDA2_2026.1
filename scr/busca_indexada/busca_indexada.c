#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100606
#define TAM_NOME 200

// STRUCTS

typedef struct {
    char nome[TAM_NOME];
} Filme;

typedef struct {
    char chave[TAM_NOME];
    int posicao;
} Indice;

// COMPARADOR PARA ORDENAÇÃO

int comparar(const void *a, const void *b) {
    return strcmp(((Filme*)a)->nome, ((Filme*)b)->nome);
}

// CRIAR INDICE

Indice* criarIndice(Filme filmes[], int n, int tamanho_bloco, int *num_indices) {
    
    *num_indices = (n + tamanho_bloco - 1) / tamanho_bloco;

    Indice *indice = (Indice *) malloc((*num_indices) * sizeof(Indice));

    int j = 0;

    for (int i = 0; i < n; i += tamanho_bloco) {
        strcpy(indice[j].chave, filmes[i].nome);
        indice[j].posicao = i;
        j++;
    }

    return indice;
}

// BUSCA INDEXADA

int buscaIndexada(Filme filmes[], int n, Indice indice[], int num_indices, char *chave_busca) {

    int i = 0;

    // encontra bloco inicial
    while (i < num_indices - 1 && strcmp(indice[i + 1].chave, chave_busca) <= 0) {
        i++;
    }

    // busca sequencial a partir do bloco
    for (int b = i; b < num_indices; b++) {

        int inicio = indice[b].posicao;
        int fim = (b == num_indices - 1) ? n : indice[b + 1].posicao;

        for (int j = inicio; j < fim; j++) {

            int cmp = strcmp(filmes[j].nome, chave_busca);

            if (cmp == 0) {
                return j;
            }

            if (cmp > 0) {
                return -1;
            }
        }
    }

    return -1;
}

// MAIN

int main() {

    Filme *filmes = (Filme *) malloc(MAX * sizeof(Filme));
    int n = 0;

    FILE *fp = fopen("../../data/movies_ordenado.txt", "r");

    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // leitura do arquivo
    while (fgets(filmes[n].nome, TAM_NOME, fp)) {

        filmes[n].nome[strcspn(filmes[n].nome, "\r\n")] = 0;

        n++;

        if (n >= MAX) {
            printf("Limite de filmes atingido.\n");
            break;
        }
    }

    fclose(fp);

    printf("Total de filmes carregados: %d\n", n);

    // ordenação correta
    qsort(filmes, n, sizeof(Filme), comparar);

    // tamanho do bloco
    int tamanho_bloco = (int) sqrt(n);
    if (tamanho_bloco == 0) tamanho_bloco = 1;

    int num_indices;

    // criar índice
    Indice *indice = criarIndice(filmes, n, tamanho_bloco, &num_indices);

    // entrada do usuário
    char busca[TAM_NOME];
    printf("\nDigite o nome do filme: ");
    fgets(busca, TAM_NOME, stdin);

    busca[strcspn(busca, "\r\n")] = 0;

    // busca
    int pos = buscaIndexada(filmes, n, indice, num_indices, busca);

    // resultado
    if (pos != -1) {
        printf("\nFilme encontrado!\n");
        printf("Posicao: %d\n", pos);
        printf("Nome: %s\n", filmes[pos].nome);
    } else {
        printf("\nFilme nao encontrado.\n");
    }

    free(indice);
    free(filmes);

    return 0;
}