#include <stdio.h>

int main() {
    int a, b;
    int result = 1;
    int i;

    printf("Enter two positive integers a and b: ");
    scanf("%d %d", &a, &b);

    for (i = 0; i < b; i++) {
        result *= a;
    }

    printf("%d^%d = %d\n", a, b, result);

    return 0;
}

/* Example Output:
Enter two positive integers a and b: 2 3
2^3 = 8
*/
