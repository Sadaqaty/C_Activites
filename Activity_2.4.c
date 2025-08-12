#include <stdio.h>

int main() {
    float sideLength, area;

    printf("Enter the length of one side of the square: ");
    scanf("%f", &sideLength);

    area = sideLength * sideLength;

    printf("The area of the square is: %.2f\n", area);

    return 0;
}
