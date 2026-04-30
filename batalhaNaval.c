#include <stdio.h>

#define TAM 10        // Tamanho do tabuleiro (10x10)
#define NAVIO_TAM 3   // Tamanho fixo dos navios

int main() {
    int tabuleiro[TAM][TAM];

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int navio_horizontal[NAVIO_TAM] = {3, 3, 3};
    int navio_vertical[NAVIO_TAM] = {3, 3, 3};

    int linha_h = 2, coluna_h = 4;
    int linha_v = 5, coluna_v = 7;

    if (coluna_h + NAVIO_TAM > TAM) {
        printf("Erro: Navio horizontal fora dos limites!\n");
        return 1;
    }

    if (linha_v + NAVIO_TAM > TAM) {
        printf("Erro: Navio vertical fora dos limites!\n");
        return 1;
    }

    for (int i = 0; i < NAVIO_TAM; i++) {
        if (tabuleiro[linha_h][coluna_h + i] != 0) {
            printf("Erro: Sobreposição no navio horizontal!\n");
            return 1;
        }
    }

    for (int i = 0; i < NAVIO_TAM; i++) {
        if (tabuleiro[linha_v + i][coluna_v] != 0) {
            printf("Erro: Sobreposição no navio vertical!\n");
            return 1;
        }
    }

    for (int i = 0; i < NAVIO_TAM; i++) {
        tabuleiro[linha_h][coluna_h + i] = navio_horizontal[i];
    }

    for (int i = 0; i < NAVIO_TAM; i++) {
        tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
    }

    printf("\nTabuleiro Batalha Naval (10x10):\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}