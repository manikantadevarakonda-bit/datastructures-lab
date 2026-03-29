#include <stdio.h>
void bubbleSort(int arr[], int n){
    int i, j, temp;
 for (i = 0; i < n- 1; i++) {
     for (j = 0; j < n- i- 1; j++) {
         if (arr[j] > arr[j + 1]) {
             temp = arr[j];
             arr[j] = arr[j + 1];
              arr[j + 1] = temp;
         }
     }
 }
}
int main() {
int n;
scanf("%d", &n);
if (n < 2 || n > 20) return 1;
 int viewing_times[n];
for (int i = 0; i < n; i++) {
     scanf("%d", &viewing_times[i]);
}
 bubbleSort(viewing_times, n);
 for (int i = 0; i < n; i++) {
    printf("%d", viewing_times[i]);
if (i < n- 1) printf(" ");
 }
 printf("\n");
return 0;
}