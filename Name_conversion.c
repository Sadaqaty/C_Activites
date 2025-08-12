#include <stdio.h>
#include <ctype.h>

int main() {
    char firstName[50], lastName[50];
    int i;

    printf("Enter your first name: ");
    scanf("%s", firstName);
    printf("Enter your last name: ");
    scanf("%s", lastName);

    for (i = 0; firstName[i] != '\0'; i++) {
        firstName[i] = toupper(firstName[i]);
    }

    for (i = 0; lastName[i] != '\0'; i++) {
        lastName[i] = tolower(lastName[i]);
    }

    printf("First Name in Uppercase: %s\n", firstName);
    printf("Last Name in Lowercase: %s\n", lastName);

    return 0;
}
