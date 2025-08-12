#include <stdio.h>

float calculateInterest(float amount, float interestRate) {
    return amount * (interestRate / 100);
}

int main() {
    float principal = 1000.0, rate = 5.0;
    printf("The interest on $%.2f at %.2f%% is $%.2f\n", principal, rate, calculateInterest(principal, rate));
    return 0;
}
