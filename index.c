#include <stdio.h>
int main() {
    int array[100]; 
    int size, index, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    printf("Enter the index to delete (0 to %d): ", size - 1);
    scanf("%d", &index);
    if (index < 0 || index >= size) {
        printf("Invalid index. Deletion failed.\n");
    } else {
        for (i = index; i < size - 1; i++) {
            array[i] = array[i + 1];
        }
        size--;
        printf("Array after deletion:\n");
        for (i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
    return 0;
}
