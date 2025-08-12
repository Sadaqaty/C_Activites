#include <stdio.h>

int main() {
    int num1, num2, choice;
    float result;

    printf("Enter the first integer: ");
    scanf("%d", &num1);
    printf("Enter the second integer: ");
    scanf("%d", &num2);

    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            result = num1 + num2;
            printf("Result of Addition: %d\n", (int)result);
            break;
        case 2:
            result = num1 - num2;
            printf("Result of Subtraction: %d\n", (int)result);
            break;
        case 3:
            result = num1 * num2;
            printf("Result of Multiplication: %d\n", (int)result);
            break;
        case 4:
            if (num2 != 0) {
                result = (float)num1 / num2;
                printf("Result of Division: %.2f\n", result);
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        default:
            printf("Invalid choice! Please select a number between 1 and 4.\n");
    }

    return 0;
}

/* Example Output:
Enter the first integer: 10
Enter the second integer: 5
Choose an operation:
1. Addition
2. Subtraction
3. Multiplication
4. Division
Enter your choice (1-4): 4
Result of Division: 2.00
*/
