#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 1000

void write_ppm(const char *filename, unsigned char *img) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    fprintf(f, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(img, 1, WIDTH * HEIGHT * 3, f);
    fclose(f);
}

void julia() {
    unsigned char img[WIDTH * HEIGHT * 3];
    double c_re = -0.7, c_im = 0.27015; // Julia set constants

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double re = (x - WIDTH / 2.0) * 4.0 / WIDTH;
            double im = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
            int iter;
            for (iter = 0; iter < MAX_ITER; iter++) {
                double re2 = re * re, im2 = im * im;
                if (re2 + im2 > 4.0) break;
                im = 2 * re * im + c_im;
                re = re2 - im2 + c_re;
            }

            int color = iter % 256;
            img[(y * WIDTH + x) * 3] = color;
            img[(y * WIDTH + x) * 3 + 1] = color;
            img[(y * WIDTH + x) * 3 + 2] = color;
        }
    }
    write_ppm("julia.ppm", img);
}

int main() {
    julia();
    return 0;
}
