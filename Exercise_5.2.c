#include <stdio.h>

int power(int x, int y) {
    int result = 1;
    for (int i = 0; i < y; i++) {
        result *= x;
    }
    return result;
}

int main() {
    int base = 2, exponent = 3;
    printf("%d raised to the power %d is %d\n", base, exponent, power(base, exponent));
    return 0;
}
