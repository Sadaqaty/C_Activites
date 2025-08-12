#include <stdio.h>

void printTable(int num) {
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    }
}

int main() {
    int number;

    // Input number from user
    printf("Enter a number to print its table: ");
    scanf("%d", &number);

    // Print the table of the given number
    printTable(number);

    return 0;
}
