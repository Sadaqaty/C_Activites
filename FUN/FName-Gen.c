#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const char* names[] = {
        "Fluffy",
        "Sparkle",
        "Wobble",
        "Doodle"
    };

    srand(time(NULL));
    int index = rand() % 4;
    printf("Your new funny name is: %s\n", names[index]);
    return 0;
}
