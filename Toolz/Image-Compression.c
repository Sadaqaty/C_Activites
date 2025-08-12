#include <stdio.h>
#include <stdlib.h>

void rle_encode(const char *input, const char *output) {
    FILE *in = fopen(input, "rb");
    FILE *out = fopen(output, "wb");
    if (!in || !out) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    unsigned char current, prev;
    size_t count = 0;

    prev = fgetc(in);
    while ((current = fgetc(in)) != EOF) {
        if (current == prev) {
            count++;
        } else {
            fwrite(&count, sizeof(size_t), 1, out);
            fwrite(&prev, sizeof(unsigned char), 1, out);
            prev = current;
            count = 1;
        }
    }
    fwrite(&count, sizeof(size_t), 1, out);
    fwrite(&prev, sizeof(unsigned char), 1, out);

    fclose(in);
    fclose(out);
}

int main() {
    rle_encode("image.bin", "image.rle");
    return 0;
}
