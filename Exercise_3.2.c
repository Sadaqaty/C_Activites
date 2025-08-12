#include <stdio.h>

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number % 3 == 0 && number % 10 == 5) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}

/* Example Output:
Enter a number: 75
YES
*/
