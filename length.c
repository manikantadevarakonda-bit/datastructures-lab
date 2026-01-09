#include <stdio.h>
int main() {
    char str[100];
    char *ptr;
    int length = 0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    ptr = str;
    while (*ptr != '\0') {
        length++;
        ptr++;
    }
    if (length > 0 && str[length - 1] == '\n') {
        length--;
    }
    printf("Length of the string: %d\n", length);
    return 0;
}
