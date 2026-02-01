#include <stdio.h>
int main() {
    int array1[] = {10, 20, 30, 40};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int array2[] = {50, 60, 70};
    int size2 = sizeof(array2) / sizeof(array2[0]);
    int mergedSize = size1 + size2;
    int mergedArray[mergedSize];
    for (int i = 0; i < size1; i++) {
        mergedArray[i] = array1[i];
    }
    for (int j = 0; j < size2; j++) {
        mergedArray[size1 + j] = array2[j];
    }
    printf("Merged array: ");
    for (int k = 0; k < mergedSize; k++) {
        printf("%d ", mergedArray[k]);
    }
    printf("\n");
    return 0;
}
