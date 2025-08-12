#include <stdio.h>

int main() {
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    if (age >= 13 && age <= 19) {
        printf("Teenager\n");
    }

    return 0;
}

/* Example Output:
Enter your age: 15
Teenager
*/
