#include <stdio.h>
int countLessEqual(int arr[], int n, int key) {
    int low = 0, high = n- 1;
    int count = 0;
     while (low <= high) {
        int mid = low + (high- low) / 2;
        if (arr[mid] <= key) {
             count = mid + 1;
         low = mid + 1;
          } else {
             high = mid- 1;

        }
     }
      return count;
}
 int main() {
     int N;
      scanf("%d", &N);
       if (N < 1 || N > 10) return 1;
        int arr[N] ;
        for (int i = 0; i < N; i++) {
             scanf("%d", &arr[i]);
        }
        int key ;
         scanf("%d", &key);
          int result = countLessEqual(arr, N, key);
           printf("%d\n", result);
           return 0;
 }