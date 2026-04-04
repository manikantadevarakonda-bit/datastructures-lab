#include <stdio.h>
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
}
int partition(int arr[], int low, int high, int n) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    printf("After partitioning with pivot %d: ", pivot);
    printArray(arr, n);
    return (i + 1);
}
void quickSort(int arr[], int low, int high, int n) {
    if (low < high) {
        int pi = partition(arr, low, high, n);
        quickSort(arr, low, pi - 1, n);
        quickSort(arr, pi + 1, high, n);
    }
}
int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;
    int books[N];
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &books[i]) != 1) break;
    }
    quickSort(books, 0, N - 1, N);
    return 0;
}