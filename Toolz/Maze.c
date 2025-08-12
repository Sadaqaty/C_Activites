#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void init_maze(char maze[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            maze[i][j] = (rand() % 2 == 0) ? ' ' : '#'; // Random walls and paths
        }
    }
    maze[0][0] = 'S'; // Start
    maze[SIZE-1][SIZE-1] = 'E'; // End
}

void print_maze(char maze[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    char maze[SIZE][SIZE];
    init_maze(maze);
    print_maze(maze);
    return 0;
}
