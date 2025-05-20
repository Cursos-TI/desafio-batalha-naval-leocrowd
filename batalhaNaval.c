#include <stdio.h>

#define TAMANHO 10        // Tamanho fixo do tabuleiro 10x10
#define TAMANHO_NAVIO 3   // Cada navio ocupa 3 posições
#define AGUA 0
#define NAVIO 3

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializa todo o tabuleiro com 0 (água)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // === NAVIO HORIZONTAL ===
    int navioH[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};

    int linhaH = 2;    // Linha onde o navio horizontal começará
    int colunaH = 4;   // Coluna inicial do navio horizontal

    // Verifica se cabe no tabuleiro (horizontal)
    if (colunaH + TAMANHO_NAVIO <= TAMANHO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica se já existe outro navio na posição
            if (tabuleiro[linhaH][colunaH + i] != AGUA) {
                printf("Erro: Sobreposição detectada para navio horizontal!\n");
                return 1;
            }
            tabuleiro[linhaH][colunaH + i] = navioH[i];
        }
    } else {
        printf("Erro: Navio horizontal ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // === NAVIO VERTICAL ===
    int navioV[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};

    int linhaV = 5;   // Linha inicial do navio vertical
    int colunaV = 7;  // Coluna onde o navio vertical será posicionado

    // Verifica se cabe no tabuleiro (vertical)
    if (linhaV + TAMANHO_NAVIO <= TAMANHO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != AGUA) {
                printf("Erro: Sobreposição detectada para navio vertical!\n");
                return 1;
            }
            tabuleiro[linhaV + i][colunaV] = navioV[i];
        }
    } else {
        printf("Erro: Navio vertical ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // === EXIBIÇÃO DO TABULEIRO ===
    printf("\nTabuleiro final:\n\n");

    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
