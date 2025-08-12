#include <stdio.h>

int main() {
    char ch = 'A';
    int i, j;
    int rows = 5; 
    
    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= i; j++) {
            printf("%c", ch++);
        }
        printf("\n");
    }

    return 0;
}

/* Example Output:
A
BC
DEF
GHIJ
KLMN
*/
