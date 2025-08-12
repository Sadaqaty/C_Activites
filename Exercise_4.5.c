#include <stdio.h>

int main() {
    int numbers[10];
    int product;

    printf("Enter 10 numbers:\n");
    for (int i = 0; i < 10; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    product = numbers[0] * numbers[9];

    printf("The product of the first and last element is: %d\n", product);

    return 0;
}

/* Example Output:
Enter 10 numbers:
Number 1: 2
Number 2: 3
Number 3: 4
...
Number 10: 5
The product of the first and last element is: 10
*/
