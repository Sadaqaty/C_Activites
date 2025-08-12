#include <stdio.h>

int main() {
    int totalSeconds, hours, minutes, seconds;

    printf("Enter the total number of seconds: ");
    scanf("%d", &totalSeconds);

    hours = totalSeconds / 3600;
    minutes = (totalSeconds % 3600) / 60;
    seconds = totalSeconds % 60;

    printf("Equivalent time: %d hours, %d minutes, %d seconds\n", hours, minutes, seconds);

    return 0;
}
