#include <stdio.h>

int main() {
    int i;
    float marks[30], sum = 0.0, average;

    printf("Enter the marks obtained by 30 students:\n");
    for (i = 0; i < 30; i++) {
        printf("Student %d: ", i + 1);
        scanf("%f", &marks[i]);
        sum += marks[i];
    }

    average = sum / 30;

    printf("The average marks of the class is: %.2f\n", average);

    return 0;
}

/* Example Output:
Enter the marks obtained by 30 students:
Student 1: 85
Student 2: 78
...
Student 30: 92
The average marks of the class is: 84.23
*/
