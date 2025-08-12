#include <stdio.h>

int main() {
    int year;

    printf("Enter a year: ");
    scanf("%d", &year);

    if (year % 4 == 0) {
        printf("Leap Year\n");
    }

    return 0;
}

/* Example Output:
Enter a year: 2024
Leap Year
*/
