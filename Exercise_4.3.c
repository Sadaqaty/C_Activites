#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;

    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);

    printf("The Greatest Common Divisor (GCD) of %d and %d is: %d\n", num1, num2, gcd(num1, num2));

    return 0;
}

/* Example Output:
Enter two positive integers: 56 98
The Greatest Common Divisor (GCD) of 56 and 98 is: 14
*/
