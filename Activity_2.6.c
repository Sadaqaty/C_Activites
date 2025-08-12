#include <stdio.h>

int main() {
    float originalPrice, discountPercentage, discountAmount, priceAfterDiscount;

    printf("Enter the original price of the shirt: ");
    scanf("%f", &originalPrice);

    printf("Enter the discount percentage: ");
    scanf("%f", &discountPercentage);

    discountAmount = (originalPrice * discountPercentage) / 100;

    priceAfterDiscount = originalPrice - discountAmount;

    printf("\nOriginal Price: $%.2f\n", originalPrice);
    printf("Discount Amount: $%.2f\n", discountAmount);
    printf("Price After Discount: $%.2f\n", priceAfterDiscount);

    return 0;
}
