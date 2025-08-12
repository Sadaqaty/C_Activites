#include <stdio.h>

int main() {
    int choice;
    float base, height, side1, side2, area;

    printf("Choose the shape to calculate the area:\n");
    printf("1. Triangle\n");
    printf("2. Parallelogram\n");
    printf("3. Rhombus\n");
    printf("4. Trapezium\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the base of the triangle: ");
            scanf("%f", &base);
            printf("Enter the height of the triangle: ");
            scanf("%f", &height);
            area = 0.5 * base * height;
            printf("Area of the Triangle: %.2f\n", area);
            break;
        case 2:
            printf("Enter the base of the parallelogram: ");
            scanf("%f", &base);
            printf("Enter the height of the parallelogram: ");
            scanf("%f", &height);
            area = base * height;
            printf("Area of the Parallelogram: %.2f\n", area);
            break;
        case 3:
            printf("Enter the length of the first diagonal: ");
            scanf("%f", &side1);
            printf("Enter the length of the second diagonal: ");
            scanf("%f", &side2);
            area = 0.5 * side1 * side2;
            printf("Area of the Rhombus: %.2f\n", area);
            break;
        case 4:
            printf("Enter the length of the first parallel side: ");
            scanf("%f", &side1);
            printf("Enter the length of the second parallel side: ");
            scanf("%f", &side2);
            printf("Enter the height of the trapezium: ");
            scanf("%f", &height);
            area = 0.5 * (side1 + side2) * height;
            printf("Area of the Trapezium: %.2f\n", area);
            break;
        default:
            printf("Invalid choice! Please select a number between 1 and 4.\n");
    }

    return 0;
}

/* Example Output:
Choose the shape to calculate the area:
1. Triangle
2. Parallelogram
3. Rhombus
4. Trapezium
Enter your choice (1-4): 3
Enter the length of the first diagonal: 8
Enter the length of the second diagonal: 6
Area of the Rhombus: 24.00
*/
