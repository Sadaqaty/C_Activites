#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 20

void print_grid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(grid[i][j] ? "O " : ". ");
        }
        printf("\n");
    }
    printf("\n");
}

void update_grid(int grid[SIZE][SIZE]) {
    int new_grid[SIZE][SIZE] = {0};

    for (int i = 1; i < SIZE - 1; i++) {
        for (int j = 1; j < SIZE - 1; j++) {
            int live_neighbors = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue;
                    live_neighbors += grid[i + di][j + dj];
                }
            }
            if (grid[i][j] && (live_neighbors == 2 || live_neighbors == 3))
                new_grid[i][j] = 1;
            else if (!grid[i][j] && live_neighbors == 3)
                new_grid[i][j] = 1;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main() {
    int grid[SIZE][SIZE] = {0};
    grid[10][10] = 1;
    grid[10][11] = 1;
    grid[10][12] = 1;

    for (int t = 0; t < 100; t++) {
        print_grid(grid);
        update_grid(grid);
        usleep(200000); // 0.2 seconds
    }

    return 0;
}
