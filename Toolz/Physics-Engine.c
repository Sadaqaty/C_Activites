#include <stdio.h>

#define WIDTH 80
#define HEIGHT 20

typedef struct {
    float x, y, vy;
} Particle;

void update_particle(Particle *p, float gravity) {
    p->vy += gravity;
    p->y += p->vy;
    if (p->y >= HEIGHT) {
        p->y = HEIGHT;
        p->vy *= -0.5; // Simple bounce with loss of energy
    }
}

void print_particle(const Particle *p) {
    for (int i = 0; i < HEIGHT; i++) {
        if (i == (int)p->y) {
            for (int j = 0; j < WIDTH; j++) {
                if (j == (int)p->x) printf("*");
                else printf(" ");
            }
            printf("\n");
        } else {
            printf("\n");
        }
    }
}

int main() {
    Particle p = {WIDTH / 2, 0, 0};
    float gravity = 0.1;

    for (int t = 0; t < 100; t++) {
        system("clear"); // or "cls" on Windows
        update_particle(&p, gravity);
        print_particle(&p);
        usleep(50000); // 0.05 seconds
    }

    return 0;
}
