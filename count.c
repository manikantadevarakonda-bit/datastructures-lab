#include <stdio.h>
int main() {
    int arr[] = {4, 2, 8, 4, 2, 7, 8, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                break;
            }
        }
    }
    printf("The total number of duplicate elements in the array is: %d\n", count);
    return 0;
}

