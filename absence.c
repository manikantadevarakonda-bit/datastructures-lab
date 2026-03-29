 #include <stdio.h>
 int binarySearch(int arr[], int n, int x) {
     int low = 0, high = n- 1;
      while (low <= high) {
         int mid = low + (high- low) / 2;
          if (arr[mid] == x) {
             return mid;
          }
        if (arr[mid] < x) {
             low = mid + 1;
        }
         else {
            high = mid- 1;
      }
 }
 return-1;
         }
 int main() {
    int N;
    scanf("%d", &N);
     if (N < 2 || N > 10) return 1;
      int arr[N];
       for (int i = 0; i < N; i++) {
         scanf("%d", &arr[i]);
       }
        int X;
         scanf("%d", &X);
          int result = binarySearch(arr, N, X);
          if (result !=-1)  {
            printf("The target value %d is present at index %d\n", X, result);
            } else {
                printf("The target value %d is not present in the array\n", X);
          }
          return 0;
 }
             
