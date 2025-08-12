#include <stdio.h>
#include <math.h>

#define STEP_SIZE 0.01
#define INTEGRAL_LIMIT 1.0

double function(double x) {
    return x * x; // Example function f(x) = x^2
}

double integrate(double (*f)(double), double a, double b, double step) {
    double sum = 0.0;
    for (double x = a; x < b; x += step) {
        sum += (f(x) + f(x + step)) * step / 2;
    }
    return sum;
}

int main() {
    double result = integrate(function, 0.0, INTEGRAL_LIMIT, STEP_SIZE);
    printf("Integral result: %.5f\n", result);
    return 0;
}
