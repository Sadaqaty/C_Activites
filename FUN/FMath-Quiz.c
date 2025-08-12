#include <stdio.h>

int main() {
    int a = 7, b = 8, answer;

    printf("What is %d + %d?\n", a, b);
    scanf("%d", &answer);

    if (answer == a + b) {
        printf("Correct! You're a math wizard!\n");
    } else {
        printf("Oops! The correct answer is %d. Better luck next time!\n", a + b);
    }
    return 0;
}
