#include <stdio.h>

int main() {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);

    if (age < 0) {
        printf("You're from the future! Or you need to check your age.\n");
    } else if (age < 18) {
        printf("You’re still a kid! Enjoy your youth.\n");
    } else if (age < 100) {
        printf("You're officially an adult! Welcome to the club.\n");
    } else {
        printf("Wow, you’ve been around for a while! You must have great stories.\n");
    }
    return 0;
}
