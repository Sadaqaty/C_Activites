#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const char* responses[] = {
        "Yes",
        "No",
        "Maybe",
        "Ask again later",
        "Definitely not",
        "Absolutely!",
        "I'm not sure"
    };

    srand(time(NULL));
    int index = rand() % 7;
    printf("Magic 8-Ball says: %s\n", responses[index]);
    return 0;
}
