#include <stdio.h>
void swap(double* a, double* b) {
    double t = *a;
    *a = *b;
    *b = t;
}
int partition(double arr[], int low, int high) {
    double pivot = arr[high]; 
    int i = (low - 1); 
    for (int j = low; j <= high - 1; j++) {
        // Change comparison to '>' for descending order
        if (arr[j] > pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(double arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;
    double arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%lf", &arr[i]);
    }
    quickSort(arr, 0, N - 1);
    for (int i = 0; i < N; i++) {
        printf("%.2f", arr[i]);
        if (i < N - 1) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}