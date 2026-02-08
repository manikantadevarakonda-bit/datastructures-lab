#include <stdio.h>
#define MAX_TERMS 100
typedef struct {
    int row;
    int col;
    int val;
} Term;
int convertToTriplet(int matrix[10][10], int r, int c, Term triplet[]) {
    int k = 1; 
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (matrix[i][j] != 0) {
                triplet[k].row = i;
                triplet[k].col = j;
                triplet[k].val = matrix[i][j];
                k++;
            }
        }
    }
    triplet[0].row = r;
    triplet[0].col = c;
    triplet[0].val = k - 1; 
    return k - 1;
}
void transpose(Term a[], Term b[]) {
    int n = a[0].val; 
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = n;
    if (n > 0) {
        int current_b = 1;
        for (int i = 0; i < a[0].col; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[j].col == i) {
                    b[current_b].row = a[j].col;
                    b[current_b].col = a[j].row;
                    b[current_b].val = a[j].val;
                    current_b++;
                }
            }
        }
    }
}
void printTriplet(Term t[]) {
    printf("Row\tCol\tValue\n");
    for (int i = 0; i <= t[0].val; i++) {
        printf("%d\t%d\t%d\n", t[i].row, t[i].col, t[i].val);
    }
}
int main() {
    int r, c, matrix[10][10];
    Term original[MAX_TERMS], transposed[MAX_TERMS];
    printf("Enter rows and columns of the link matrix: ");
    scanf("%d %d", &r, &c);
    printf("Enter the adjacency matrix (0s and 1s):\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    convertToTriplet(matrix, r, c, original);
    printf("\n--- Original Triplet Representation ---\n");
    printTriplet(original);
    transpose(original, transposed);
    printf("\n--- Transposed Triplet Representation ---\n");
    printTriplet(transposed);
    return 0;
}
