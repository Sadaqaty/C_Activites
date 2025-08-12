#include <stdio.h>

int main() {
    int num = 7;
    printf("Addition table for %d:\n", num);
    for (int i = 1; i <= 10; i++) {
        printf("%d + %d = %d - Fun times!\n", num, i, num + i);
    }
    return 0;
}
