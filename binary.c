#include <stdio.h>
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; 
        }
    }
    
    return -1; 
}
int main() {
    int array[] = {2, 4, 0, 8, 6, 10, 23, 1, 9};
    int key_to_find = 23;
    int n = sizeof(array) / sizeof(array[0]);
    int result = linearSearch(array, n, key_to_find);
    if (result == -1) {
        printf("Element %d not found in the array.\n", key_to_find);
    } else {
        printf("Element %d found at index: %d\n", key_to_find, result);
    }
    return 0;
}
