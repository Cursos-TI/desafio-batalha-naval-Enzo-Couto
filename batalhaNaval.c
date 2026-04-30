#include <stdio.h>

#define TAM 10
#define NAVIO_TAM 3
#define H 5
#define AGUA 0
#define NAVIO 3
#define EFEITO 5

void inicializarTabuleiro(int tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tab[i][j] = AGUA;
}

int podePosicionar(int tab[TAM][TAM], int l0, int c0, int dL, int dC) {
    for (int i = 0; i < NAVIO_TAM; i++) {
        int l = l0 + i * dL;
        int c = c0 + i * dC;

        if (l < 0 || l >= TAM || c < 0 || c >= TAM) return 0;
        if (tab[l][c] != AGUA) return 0;
    }
    return 1;
}

// Posiciona navio
void posicionarNavio(int tab[TAM][TAM], int l0, int c0, int dL, int dC) {
    for (int i = 0; i < NAVIO_TAM; i++) {
        int l = l0 + i * dL;
        int c = c0 + i * dC;
        tab[l][c] = NAVIO;
    }
}

void construirCone(int m[H][H]) {
    int centro = H / 2;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            // distância horizontal até o centro
            int dx = j - centro;
            if (dx <= i && -dx <= i) {
                m[i][j] = 1;
            } else {
                m[i][j] = 0;
            }
        }
    }
}

void construirCruz(int m[H][H]) {
    int centro = H / 2;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (i == centro || j == centro) {
                m[i][j] = 1;
            } else {
                m[i][j] = 0;
            }
        }
    }
}

void construirOctaedro(int m[H][H]) {
    int centro = H / 2;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            int di = i - centro; if (di < 0) di = -di;
            int dj = j - centro; if (dj < 0) dj = -dj;

            if (di + dj <= centro) {
                m[i][j] = 1;
            } else {
                m[i][j] = 0;
            }
        }
    }
}

void aplicarHabilidade(int tab[TAM][TAM], int m[H][H], int origL, int origC) {
    int centro = H / 2;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (m[i][j] == 1) {
                int l = origL + (i - centro);
                int c = origC + (j - centro);

                if (l >= 0 && l < TAM && c >= 0 && c < TAM) {
                    if (tab[l][c] == AGUA) {
                        tab[l][c] = EFEITO;
                    }
                }
            }
        }
    }
}

// Impressão com legenda visual
void imprimirTabuleiro(int tab[TAM][TAM]) {
    printf("\nLegenda: 0=Agua  3=Navio  5=Habilidade\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tab[TAM][TAM];

    inicializarTabuleiro(tab);

    if (podePosicionar(tab, 1, 2, 0, 1)) posicionarNavio(tab, 1, 2, 0, 1); // horizontal
    if (podePosicionar(tab, 4, 5, 1, 0)) posicionarNavio(tab, 4, 5, 1, 0); // vertical
    if (podePosicionar(tab, 6, 1, 1, 1)) posicionarNavio(tab, 6, 1, 1, 1); // diagonal
    if (podePosicionar(tab, 0, 9, 1, -1)) posicionarNavio(tab, 0, 9, 1, -1); // diagonal

    int cone[H][H];
    int cruz[H][H];
    int octaedro[H][H];

    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    int origemConeL = 2, origemConeC = 2;
    int origemCruzL = 5, origemCruzC = 5;
    int origemOctL  = 7, origemOctC  = 7;

    aplicarHabilidade(tab, cone, origemConeL, origemConeC);
    aplicarHabilidade(tab, cruz, origemCruzL, origemCruzC);
    aplicarHabilidade(tab, octaedro, origemOctL, origemOctC);

    imprimirTabuleiro(tab);

    return 0;
}