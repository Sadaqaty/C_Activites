#include <stdio.h>

int main() {
    int a, b, result;
    char operator;

    printf("Enter a simple math operation (e.g., 5 + 3): ");
    scanf("%d %c %d", &a, &operator, &b);

    switch (operator) {
        case '+':
            result = a + b;
            printf("The result of %d + %d is %d. Easy peasy!\n", a, b, result);
            break;
        case '-':
            result = a - b;
            printf("The result of %d - %d is %d. Nice try!\n", a, b, result);
            break;
        case '*':
            result = a * b;
            printf("The result of %d * %d is %d. Multiplying like a pro!\n", a, b, result);
            break;
        case '/':
            if (b != 0) {
                result = a / b;
                printf("The result of %d / %d is %d. Division is fun!\n", a, b, result);
            } else {
                printf("Division by zero is not allowed. Nice try though!\n");
            }
            break;
        default:
            printf("Unknown operator. Try again with +, -, *, or /.\n");
    }
    return 0;
}
