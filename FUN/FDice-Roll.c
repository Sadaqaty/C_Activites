#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int roll = rand() % 6 + 1;
    printf("You rolled a %d! Hope it's lucky!\n", roll);
    return 0;
}
