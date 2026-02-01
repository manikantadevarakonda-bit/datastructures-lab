#include <stdio.h>

int main() {
    int n, i, arr[100];
    printf("Enter the number of elements (1 to 100): ");
    scanf("%d", &n);
    if (n < 1 || n > 100) {
        printf("Invalid input: Please enter a number between 1 and 100.\n");
        return 1; 
    }
    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\nElements in reverse order are:\n");
    for (i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
