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

int check_winner(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0] == 'X' ? 10 : (board[i][0] == 'O' ? -10 : 0);
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i] == 'X' ? 10 : (board[0][i] == 'O' ? -10 : 0);
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0] == 'X' ? 10 : (board[0][0] == 'O' ? -10 : 0);
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2] == 'X' ? 10 : (board[0][2] == 'O' ? -10 : 0);
    return 0;
}

int minimax(char board[SIZE][SIZE], int depth, int is_max) {
    int score = check_winner(board);

    if (score == 10) return score;
    if (score == -10) return score;
    if (!is_moves_left(board)) return 0;

    int best;
    if (is_max) {
        best = -1000;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    best = max(best, minimax(board, depth + 1, !is_max));
                    board[i][j] = ' ';
                }
            }
        }
    } else {
        best = 1000;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    best = min(best, minimax(board, depth + 1, !is_max));
                    board[i][j] = ' ';
                }
            }
        }
    }
    return best;
}

int main() {
    char board[SIZE][SIZE] = {
        {'X', 'O', 'X'},
        {' ', 'X', 'O'},
        {' ', ' ', 'X'}
    };

    print_board(board);
    int result = minimax(board, 0, 1);
    printf("Best score: %d\n", result);
    return 0;
}
