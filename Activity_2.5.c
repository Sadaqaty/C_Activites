#include <stdio.h>

int main() {
    int ballsInJarA, ballsInJarB, totalBalls;

    printf("Enter the number of balls in Jar A: ");
    scanf("%d", &ballsInJarA);

    printf("Enter the number of balls in Jar B: ");
    scanf("%d", &ballsInJarB);

    totalBalls = ballsInJarA + ballsInJarB;

    printf("The total number of balls is: %d\n", totalBalls);

    return 0;
}
