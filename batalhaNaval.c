#include <stdio.h>

#define TAB_SIZE 10

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAB_SIZE][TAB_SIZE]) {
    for(int i=0; i<TAB_SIZE; i++) {
        for(int j=0; j<TAB_SIZE; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para verificar se uma posição está dentro dos limites do tabuleiro
int estaDentro(int linha, int coluna) {
    return (linha >= 0 && linha < TAB_SIZE && coluna >= 0 && coluna < TAB_SIZE);
}

// Função para verificar sobreposição de navios
int podePosicionar(int tabuleiro[TAB_SIZE][TAB_SIZE], int linha, int coluna) {
    return estaDentro(linha, coluna) && (tabuleiro[linha][coluna] == 0);
}

// Posiciona um navio ortogonal (horizontal ou vertical) de tamanho 3
int posicionarNavioOrtogonal(int tabuleiro[TAB_SIZE][TAB_SIZE], int linha, int coluna, int horizontal) {
    // horizontal = 1 -> horizontal; 0 -> vertical
    for(int k=0; k<3; k++) {
        int r = linha + (horizontal ? 0 : k);
        int c = coluna + (horizontal ? k : 0);
        if (!podePosicionar(tabuleiro, r, c)) {
            return 0; // não pode posicionar, sobreposição ou fora do tabuleiro
        }
    }
    for(int k=0; k<3; k++) {
        int r = linha + (horizontal ? 0 : k);
        int c = coluna + (horizontal ? k : 0);
        tabuleiro[r][c] = 3;
    }
    return 1;
}

// Posiciona um navio diagonal (tamanho 3) - diagonal principal ou secundária
int posicionarNavioDiagonal(int tabuleiro[TAB_SIZE][TAB_SIZE], int linha, int coluna, int diagonalPrincipal) {
    // diagonalPrincipal = 1 -> linha e coluna aumentam juntos ( \ )
    // diagonalPrincipal = 0 -> linha aumenta e coluna diminui ( / )
    for(int k=0; k<3; k++) {
        int r = linha + k;
        int c = diagonalPrincipal ? coluna + k : coluna - k;
        if (!podePosicionar(tabuleiro, r, c)) {
            return 0; // inválido
        }
    }
    for(int k=0; k<3; k++) {
        int r = linha + k;
        int c = diagonalPrincipal ? coluna + k : coluna - k;
        tabuleiro[r][c] = 3;
    }
    return 1;
}

// Cria a matriz de habilidade cone 7x7
void criarMatrizCone(int cone[7][7]) {
    /*
    Formato do cone (1 = área de efeito):
    Linha 0:        0 0 0 1 0 0 0
    Li
