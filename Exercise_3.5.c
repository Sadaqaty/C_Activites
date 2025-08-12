#include <stdio.h>

int main() {
    float side1, side2, side3, hypotenuse, base, height;

    printf("Enter the length of the first side: ");
    scanf("%f", &side1);
    printf("Enter the length of the second side: ");
    scanf("%f", &side2);
    printf("Enter the length of the third side: ");
    scanf("%f", &side3);

    // Find the hypotenuse and base & height
    if (side1 > side2 && side1 > side3) {
        hypotenuse = side1;
        base = side2;
        height = side3;
    } else if (side2 > side1 && side2 > side3) {
        hypotenuse = side2;
        base = side1;
        height = side3;
    } else {
        hypotenuse = side3;
        base = side1;
        height = side2;
    }

    if (hypotenuse * hypotenuse == (base * base + height * height)) {
        printf("The triangle is a right angle triangle.\n");
    } else {
        printf("The triangle is not a right angle triangle.\n");
    }

    return 0;
}

/* Example Output:
Enter the length of the first side: 5
Enter the length of the second side: 4
Enter the length of the third side: 3
The triangle is a right angle triangle.
*/
