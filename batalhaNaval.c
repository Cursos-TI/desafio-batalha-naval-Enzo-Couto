#include <stdio.h>

#define TAM 10
#define NAVIO_TAM 3

// inicializar tabuleiro
void inicializarTabuleiro(int tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tab[i][j] = 0;
        }
    }
}

// validar posição
int podePosicionar(int tab[TAM][TAM], int linha, int coluna, int dLinha, int dColuna) {
    for (int i = 0; i < NAVIO_TAM; i++) {
        int l = linha + i * dLinha;
        int c = coluna + i * dColuna;

        if (l < 0 || l >= TAM || c < 0 || c >= TAM) {
            return 0;
        }

        if (tab[l][c] != 0) {
            return 0;
        }
    }
    return 1;
}

void posicionarNavio(int tab[TAM][TAM], int linha, int coluna, int dLinha, int dColuna) {
    for (int i = 0; i < NAVIO_TAM; i++) {
        int l = linha + i * dLinha;
        int c = coluna + i * dColuna;
        tab[l][c] = 3;
    }
}

//imprimir tabuleiro
void imprimirTabuleiro(int tab[TAM][TAM]) {
    printf("\nTabuleiro Batalha Naval (10x10):\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    inicializarTabuleiro(tabuleiro);

    // Horizontal
    if (podePosicionar(tabuleiro, 1, 2, 0, 1)) {
        posicionarNavio(tabuleiro, 1, 2, 0, 1);
    }

    // Vertical
    if (podePosicionar(tabuleiro, 4, 5, 1, 0)) {
        posicionarNavio(tabuleiro, 4, 5, 1, 0);
    }

    // Diagonal principal
    if (podePosicionar(tabuleiro, 6, 1, 1, 1)) {
        posicionarNavio(tabuleiro, 6, 1, 1, 1);
    }

    // Diagonal secundária
    if (podePosicionar(tabuleiro, 0, 9, 1, -1)) {
        posicionarNavio(tabuleiro, 0, 9, 1, -1);
    }

    imprimirTabuleiro(tabuleiro);

    return 0;
}