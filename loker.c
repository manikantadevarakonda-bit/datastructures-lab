#include <stdio.h>
void insertionSortDescending(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;
    int lockers[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &lockers[i]);
    }
    insertionSortDescending(lockers, N);
    for (int i = 0; i < N; i++) {
        printf("%d", lockers[i]);
        if (i < N - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}