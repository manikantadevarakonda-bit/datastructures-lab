#include <stdio.h>
int main() {
    int array[] = {10, 20, 30, 40, 50};
    int n = sizeof(array) / sizeof(array[0]);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += array[i];
    }
    printf("The sum of all elements in the array is: %d\n", sum);
    return 0;
}

