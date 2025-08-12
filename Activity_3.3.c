#include <stdio.h>

int main() {
    float temperature;

    printf("Enter your body temperature: ");
    scanf("%f", &temperature);

    if (temperature > 98.6) {
        printf("You have fever. Time to binge-watch some shows under the blankets!\n");
    } else {
        printf("You don't have fever. Keep being awesome!\n");
    }

    return 0;
}

/* Example Output:
Enter your body temperature: 99.1
You have fever. Time to binge-watch some shows under the blankets!
*/
