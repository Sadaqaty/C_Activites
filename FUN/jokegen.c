#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const char* jokes[] = {
        "Why don't scientists trust atoms? Because they make up everything!",
        "Why did the math book look sad? Because it had too many problems.",
        "Why don't programmers like nature? It has too many bugs.",
        "What do you get if you cross a cat with a dark horse? Kitty Perry."
    };

    srand(time(NULL));
    int index = rand() % 4;
    printf("Joke of the day: %s\n", jokes[index]);
    return 0;
}
