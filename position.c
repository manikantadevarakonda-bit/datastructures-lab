#include <stdio.h>
int main() {
    int arr[100]; 
    int size, i, element, position;
    printf("Enter the current size of the array: ");
    scanf("%d", &size);
    printf("Enter elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be inserted: ");
    scanf("%d", &element);
    printf("Enter the position (1 to %d) to insert the element: ", size + 1);
    scanf("%d", &position);
    if (position < 1 || position > size + 1) {
        printf("Invalid position!\n");
    } else if (size >= 100) {
        printf("Array is full, cannot insert more elements!\n");
    } else {
        for (i = size - 1; i >= position - 1; i--) {
            arr[i + 1] = arr[i];
        }
        arr[position - 1] = element;
        size++;
        printf("Array after insertion:\n");
        for (i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}
