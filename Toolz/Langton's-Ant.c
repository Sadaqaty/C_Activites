#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 20
#define STEPS 10000

typedef enum { WHITE, BLACK } Cell;

typedef struct {
    int x, y;
    int direction; // 0: up, 1: right, 2: down, 3: left
} Ant;

void print_grid(Cell grid[HEIGHT][WIDTH], Ant ant) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (y == ant.y && x == ant.x) {
                printf("A");
            } else {
                printf(grid[y][x] == WHITE ? "." : "#");
            }
        }
        printf("\n");
    }
}

void update_ant(Ant *ant, Cell grid[HEIGHT][WIDTH]) {
    if (grid[ant->y][ant->x] == WHITE) {
        grid[ant->y][ant->x] = BLACK;
        ant->direction = (ant->direction + 1) % 4;
    } else {
        grid[ant->y][ant->x] = WHITE;
        ant->direction = (ant->direction + 3) % 4;
    }

    switch (ant->direction) {
        case 0: ant->y = (ant->y - 1 + HEIGHT) % HEIGHT; break;
        case 1: ant->x = (ant->x + 1) % WIDTH; break;
        case 2: ant->y = (ant->y + 1) % HEIGHT; break;
        case 3: ant->x = (ant->x - 1 + WIDTH) % WIDTH; break;
    }
}

int main() {
    Cell grid[HEIGHT][WIDTH];
    Ant ant = {WIDTH / 2, HEIGHT / 2, 0};

    // Initialize grid
    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            grid[y][x] = WHITE;

    for (int step = 0; step < STEPS; step++) {
        system("clear"); // or "cls" on Windows
        print_grid(grid, ant);
        update_ant(&ant, grid);
        usleep(100000); // 0.1 seconds
    }

    return 0;
}
