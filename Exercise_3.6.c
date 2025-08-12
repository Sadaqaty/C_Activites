#include <stdio.h>

int main() {
    float matricObtained, matricTotal, interObtained, interTotal, entranceObtained, entranceTotal;
    float matricPercentage, interPercentage, entrancePercentage;

    printf("Enter obtained and total marks in Matric: ");
    scanf("%f %f", &matricObtained, &matricTotal);
    printf("Enter obtained and total marks in Intermediate: ");
    scanf("%f %f", &interObtained, &interTotal);
    printf("Enter obtained and total marks in Entrance Test: ");
    scanf("%f %f", &entranceObtained, &entranceTotal);

    matricPercentage = (matricObtained / matricTotal) * 100;
    interPercentage = (interObtained / interTotal) * 100;
    entrancePercentage = (entranceObtained / entranceTotal) * 100;

    if (matricPercentage >= 60 && interPercentage >= 65 && entrancePercentage >= 65) {
        printf("The student is eligible for admission.\n");
    } else {
        printf("The student is not eligible for admission.\n");
    }

    return 0;
}

/* Example Output:
Enter obtained and total marks in Matric: 540 600
Enter obtained and total marks in Intermediate: 720 800
Enter obtained and total marks in Entrance Test: 130 150
The student is eligible for admission.
*/
