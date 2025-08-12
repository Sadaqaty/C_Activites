#include <stdio.h>

int main() {
    int i, j;
    long long factorial;

    for (i = 1; i <= 7; i++) {
        factorial = 1;
        for (j = 1; j <= i; j++) {
            factorial *= j;
        }
        printf("Factorial of %d is %lld\n", i, factorial);
    }

    return 0;
}

/* Example Output:
Factorial of 1 is 1
Factorial of 2 is 2
Factorial of 3 is 6
Factorial of 4 is 24
Factorial of 5 is 120
Factorial of 6 is 720
Factorial of 7 is 5040
*/
