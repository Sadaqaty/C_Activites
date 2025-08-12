#include <stdio.h>

int main() {
    int array[7] = {5, 12, 7, 20, 9, 14, 6};
    int count = 0;

    for (int i = 0; i < 7; i++) {
        if (array[i] > 10) {
            count++;
        }
    }

    printf("Number of elements greater than 10: %d\n", count);

    return 0;
}

/* Example Output:
Number of elements greater than 10: 4
*/
