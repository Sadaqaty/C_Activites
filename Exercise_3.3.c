#include <stdio.h>

int main() {
    float totalBill, discount, discountedPrice;

    printf("Enter the total bill amount: ");
    scanf("%f", &totalBill);

    if (totalBill >= 10000) {
        discount = 0.50;
    } else if (totalBill >= 5000) {
        discount = 0.35;
    } else if (totalBill >= 2500) {
        discount = 0.20;
    } else if (totalBill >= 1000) {
        discount = 0.10;
    } else {
        discount = 0.0;
    }

    discountedPrice = totalBill * (1 - discount);

    if (discount > 0) {
        printf("You got a discount of %.0f%%\n", discount * 100);
        printf("Discounted price: %.2f\n", discountedPrice);
    } else {
        printf("No discount available.\n");
        printf("Total price: %.2f\n", totalBill);
    }

    return 0;
}

/* Example Output:
Enter the total bill amount: 3000
You got a discount of 20%
Discounted price: 2400.00
*/
