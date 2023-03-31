#include <stdio.h>
#include <stdlib.h>

// Tamanho do bloco de leitura do arquivo
#define BLOCK_SIZE 10000000  // 10 milhões

int counter() {
     // Abre o arquivo para leitura
    FILE *fp;
    fp = fopen("sequencia_aleatoria.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    // Inicializa as variáveis de contagem
    long count_A = 0, count_C = 0, count_G = 0, count_T = 0;

    // Loop para ler o arquivo em blocos
    char data[BLOCK_SIZE];
    size_t read_size;
    while ((read_size = fread(data, sizeof(char), BLOCK_SIZE, fp)) > 0) {
        // Percorre o bloco contando a quantidade de cada base nitrogenada
        for (int i = 0; i < read_size; i++) {
            switch (data[i]) {
                case 'A':
                    count_A++;
                    break;
                case 'C':
                    count_C++;
                    break;
                case 'G':
                    count_G++;
                    break;
                case 'T':
                    count_T++;
                    break;
            }
        }
    }

    // Fecha o arquivo
    fclose(fp);

    // Imprime os resultados
    printf("Quantidade de bases nitrogenadas no arquivo:\n");
    printf("A: %ld\n", count_A);
    printf("C: %ld\n", count_C);
    printf("G: %ld\n", count_G);
    printf("T: %ld\n", count_T);

    return 0;
}
