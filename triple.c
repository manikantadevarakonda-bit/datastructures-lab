#include <stdio.h>
#define MAX 100
int toTriplet(int dense[MAX][MAX], int r, int c, int triplet[MAX][3]) {
    int k = 1;
    triplet[0][0] = r;
    triplet[0][1] = c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (dense[i][j] != 0) {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = dense[i][j];
                k++;
            }
        }
    }
    triplet[0][2] = k - 1; 
    return k - 1;
}
void addSparse(int a[MAX][3], int b[MAX][3], int sum[MAX][3]) {
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        printf("Error: Matrix dimensions do not match!\n");
        return;
    }
    int i = 1, j = 1, k = 1;
    sum[0][0] = a[0][0];
    sum[0][1] = a[0][1];
    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            sum[k][0] = a[i][0]; sum[k][1] = a[i][1]; sum[k][2] = a[i][2];
            i++; k++;
        } else if (b[j][0] < a[i][0] || (b[j][0] == a[i][0] && b[j][1] < a[i][1])) {
            sum[k][0] = b[j][0]; sum[k][1] = b[j][1]; sum[k][2] = b[j][2];
            j++; k++;
        } else {
            int val = a[i][2] + b[j][2];
            if (val != 0) {
                sum[k][0] = a[i][0]; sum[k][1] = a[i][1]; sum[k][2] = val;
                k++;
            }
            i++; j++;
        }
    }

    while (i <= a[0][2]) { 
        sum[k][0] = a[i][0]; sum[k][1] = a[i][1]; sum[k][2] = a[i][2];
        i++; k++;
    }
    while (j <= b[0][2]) { 
        sum[k][0] = b[j][0]; sum[k][1] = b[j][1]; sum[k][2] = b[j][2];
        j++; k++;
    }
    sum[0][2] = k - 1;
}
void displayTriplet(int triplet[MAX][3]) {
    printf("Row\tCol\tValue\n");
    for (int i = 0; i <= triplet[0][2]; i++) {
        printf("%d\t%d\t%d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
    }
}
int main() {
    int r, c, mat1[MAX][MAX], mat2[MAX][MAX];
    int trip1[MAX][3], trip2[MAX][3], result[MAX][3];
    printf("Enter dimensions (rows cols): ");
    scanf("%d %d", &r, &c);
    printf("Enter elements of Matrix 1:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) scanf("%d", &mat1[i][j]);
    printf("Enter elements of Matrix 2:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) scanf("%d", &mat2[i][j]);
    toTriplet(mat1, r, c, trip1);
    toTriplet(mat2, r, c, trip2);
    addSparse(trip1, trip2, result);
    printf("\nResultant Sparse Matrix (Triplet Form):\n");
    displayTriplet(result);
    return 0;
}