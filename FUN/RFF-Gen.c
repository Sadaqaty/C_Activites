#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const char* facts[] = {
        "Did you know? Honey never spoils!",
        "Fun fact: A group of flamingos is called a 'flamboyance'!",
        "Here's a fact: Octopuses have three hearts!",
        "Did you know? Bananas are berries, but strawberries aren't!"
    };

    srand(time(NULL));
    int index = rand() % 4;
    printf("Fun Fact: %s\n", facts[index]);
    return 0;
}
