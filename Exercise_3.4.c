#include <stdio.h>

int main() {
    float originalPrice, salePrice, profitLoss, profitLossPercentage;

    printf("Enter the original price: ");
    scanf("%f", &originalPrice);
    printf("Enter the sale price: ");
    scanf("%f", &salePrice);

    profitLoss = salePrice - originalPrice;

    if (profitLoss > 0) {
        profitLossPercentage = (profitLoss / originalPrice) * 100;
        printf("The product is sold at a profit of %.2f\n", profitLoss);
        printf("Profit percentage: %.2f%%\n", profitLossPercentage);
    } else if (profitLoss < 0) {
        profitLossPercentage = (-profitLoss / originalPrice) * 100;
        printf("The product is sold at a loss of %.2f\n", -profitLoss);
        printf("Loss percentage: %.2f%%\n", profitLossPercentage);
    } else {
        printf("The product is sold at no profit, no loss.\n");
    }

    return 0;
}

/* Example Output:
Enter the original price: 150
Enter the sale price: 180
The product is sold at a profit of 30.00
Profit percentage: 20.00%
*/
