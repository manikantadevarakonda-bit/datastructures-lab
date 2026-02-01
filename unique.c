#include <stdio.h>
void printUniqueElements(int arr[], int n) {
    printf("Unique elements in the array are: ");
    for (int i = 0; i < n; i++) {
        int isUnique = 1; 
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isUnique = 0; 
                break;
            }
        }
        if (isUnique) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 2, 8, 4, 2, 9, 5, 8, 1, 3};
    // Calculate the number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    printUniqueElements(arr, n);

    return 0;
}
