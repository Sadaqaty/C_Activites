#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, number;

    srand(time(NULL));
    number = rand() % 10 + 1;

    printf("Guess the number (1 to 10): ");
    scanf("%d", &guess);

    if (guess == number) {
        printf("Wow! You guessed it right! You're a genius!\n");
    } else {
        printf("Oops! The number was %d. Better luck next time!\n", number);
    }
    return 0;
}
