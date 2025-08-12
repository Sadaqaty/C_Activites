#include <stdio.h>

#define SIZE 3

void print_board(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner(char board[SIZE][SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return 1;
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return 1;
    return 0;
}

int main() {
    char board[SIZE][SIZE] = {
        {'X', 'O', 'X'},
        {' ', 'X', 'O'},
        {' ', ' ', 'X'}
    };
    print_board(board);
    if (check_winner(board, 'X')) printf("Player X wins!\n");
    else printf("No winner.\n");
    return 0;
}
