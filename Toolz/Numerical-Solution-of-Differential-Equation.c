#include <stdio.h>

#define STEP_SIZE 0.01
#define NUM_STEPS 1000

double f(double t, double y) {
    return -2 * t * y; // Example differential equation dy/dt = -2ty
}

void euler_method() {
    double t = 0, y = 1; // Initial condition
    FILE *f = fopen("euler_output.txt", "w");
    if (!f) {
        perror("Failed to open file");
        return;
    }
    for (int i = 0; i < NUM_STEPS; i++) {
        fprintf(f, "%f %f\n", t, y);
        y += STEP_SIZE * f(t, y);
        t += STEP_SIZE;
    }
    fclose(f);
}

int main() {
    euler_method();
    return 0;
}
