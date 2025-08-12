#include <stdio.h>

int main() {
    float percentage;

    printf("Enter your percentage of Intermediate marks: ");
    scanf("%f", &percentage);

    if (percentage >= 80) {
        printf("You are eligible to apply for the BSSE Program!\n");
    } 
    if (percentage >= 70 && percentage < 80) {
        printf("You are eligible to apply for the BSCS Program!\n");
    }
    if (percentage >= 60 && percentage < 70) {
        printf("You are eligible to apply for the BSIT Program!\n");
    }
    if (percentage < 60) {
        printf("Looks like you need a bit more magic in your grades to apply for our programs. Keep trying!\n");
    }

    return 0;
}

/* Example Output:
Enter your percentage of Intermediate marks: 75
You are eligible to apply for the BSCS Program!
*/
