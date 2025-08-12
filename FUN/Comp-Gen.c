#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const char* compliments[] = {
        "You're a star!",
        "You light up the room!",
        "You're amazing!",
        "Keep being awesome!"
    };

    srand(time(NULL));
    int index = rand() % 4;
    printf("Compliment of the day: %s\n", compliments[index]);
    return 0;
}
