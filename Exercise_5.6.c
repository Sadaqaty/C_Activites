#include <stdio.h>

void displayDigits(int number) {
    if (number < 0) {
        number = -number;
    }
    if (number == 0) {
        printf("0");
    }
    else {
        int divisor = 1;
        while (number / divisor >= 10) {
            divisor *= 10;
        }
        while (divisor > 0) {
            printf("%d ", number / divisor);
            number %= divisor;
            divisor /= 10;
        }
    }
    printf("\n");
}

int main() {
    int num = 12345;
    printf("Digits of %d are: ", num);
    displayDigits(num);
    return 0;
}
