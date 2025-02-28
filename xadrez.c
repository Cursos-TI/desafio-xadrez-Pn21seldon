#include <stdio.h>

// defininindo o tamanho do tabuleiro
#define size 8

// função para imprimir o tabuleiro
void printBoard(int board[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// movimento do bispo
void moveBispo(int board[size][size], int x, int y) {
    for (int i = 1; i < size; i++) {
        if (x + 1 < size && y + i < size) board[x + 1][y + i] = 1;
        if (x - 1 >= 0 && y + i < size) board[x - 1][y + i] = 1;
        if (x + 1 < size && y - i >= size) board[x + 1][y - i] = 1;
        if (x - 1 >= 0 && y - i >= size) board[x - 1][y - i] = 1;
    }
}

// movimento torre
void moveTorre(int board[size][size], int x, int y) {
    for (int i = 0; i < size; i++) {
        if (i != x) board[i][y] = 1; // movimento vertical
        if (i != y) board[x][i] = 1; // movimento horizontal

    }
}

// movimento da rainha
void moveRainha(int board[size][size], int x, int y) {
    for (int i = 0; i < size; i++) {
        moveTorre(board, x, y);
        moveBispo(board, x, y);
    }
}

int main() {
    int board[size][size] = {0};

    // movimento do bispo a partir da posição (4, 4)
    moveBispo(board, 4, 4);
    printf("Movimento do bispo:\n");
    printBoard(board);

    // limpando o tabuleiro
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = 0;
        }
    }

    // movimento da torre a partir da posição (4, 4)
    moveTorre(board, 4, 4);
    printf("Movimento da torre:\n");
    printBoard(board);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = 0;
        }
    }
    moveRainha(board, 4, 4);
    printf("Movimento da rainha:\n");
    printBoard(board);

    return 0;
}