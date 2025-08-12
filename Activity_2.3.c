#include <stdio.h>

int main() {
    int rollNo;
    float percentage;
    char grade;

    printf("Enter your Roll No: ");
    scanf("%d", &rollNo);

    printf("Enter your Percentage of Marks: ");
    scanf("%f", &percentage);

    printf("Enter your Grade: ");
    scanf(" %c", &grade); 

    printf("\nRoll No:       \t%d\n", rollNo);
    printf("Percentage:    \t%.2f%%\n", percentage);  
    printf("Grade:         \t%c\n", grade);

    return 0;
}
