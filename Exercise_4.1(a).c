#include <stdio.h>

int main() {
    int i, j;
    int size = 5; 
    
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

/* Example Output:
*****
*****
*****
*****
*****
*/
