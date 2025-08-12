#include <stdio.h>

void checkTriangle(int a, int b, int c) {
    if (a + b + c == 180) {
        printf("The angles %d, %d, %d form a valid triangle.\n", a, b, c);
    } else {
        printf("The angles %d, %d, %d do not form a valid triangle.\n", a, b, c);
    }
}

int main() {
    int angle1 = 60, angle2 = 60, angle3 = 60;
    checkTriangle(angle1, angle2, angle3);
    return 0;
}
