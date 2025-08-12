#include <stdio.h>

int main() {
    int number, firstDigit, secondDigit, product;

    printf("Enter a two-digit number: ");
    scanf("%d", &number);

    firstDigit = number / 10;
    secondDigit = number % 10;
    product = firstDigit + secondDigit;

    printf("The sum of the digits is: %d\n", product);

    return 0;
}
