#include <stdio.h>
int main() {   
    int numbers[100]; 
    int n, i;
    printf("Enter the number of elements (up to 100): ");
    scanf("%d", &n);
    if (n > 100 || n <= 0) {
        printf("Invalid number of elements. Please enter a number between 1 and 100.\n");
        return 1; 
    }
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }
    printf("\nElements stored in the array are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    return 0; 
}
