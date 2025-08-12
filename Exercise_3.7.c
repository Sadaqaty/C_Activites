#include <stdio.h>

int main() {
    float salary, bonus = 0;
    int experience, bonusTasks;

    printf("Enter the salary of the employee: ");
    scanf("%f", &salary);
    printf("Enter the years of experience with the company: ");
    scanf("%d", &experience);
    printf("Enter the number of bonus tasks completed: ");
    scanf("%d", &bonusTasks);

    if (experience == 2) {
        if (salary == 10000) {
            bonus = 1500;
        }
    } else if (experience == 3) {
        if (salary == 10000) {
            bonus = 2500;
        } else if (salary == 25000) {
            bonus = 2000;
        }
    } else if (experience == 4) {
        if (salary == 75000) {
            bonus = 3500;
        }
    } else if (experience == 5) {
        if (salary == 100000) {
            bonus = 5000;
        }
    }

    bonus += bonusTasks * 100; 

    printf("The bonus for the employee is: %.2f\n", bonus);

    return 0;
}

/* Example Output:
Enter the salary of the employee: 10000
Enter the years of experience with the company: 3
Enter the number of bonus tasks completed: 4
The bonus for the employee is: 2900.00
*/
