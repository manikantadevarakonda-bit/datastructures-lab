#include <stdio.h> 
void multiplyPolynomials(int A[], int B[], int m, int n) {
    int size = m + n + 1;
    int result[size];
    for (int i = 0; i < size; i++) {
        result[i] = 0;
    }
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            result[i + j] += A[i] * B[j];
        }
    }
    printf("Resulting Filter Polynomial: \n");
    for (int i = size - 1; i >= 0; i--) {
        if (result[i] != 0) {
            printf("%d", result[i]);
            if (i != 0) printf("x^%d ", i);
            if (i > 0 && result[i-1] >= 0) printf(" + ");
            else if (i > 0) printf(" ");
        }
    }
    printf("\n");
}
int main() {
    int deg1, deg2;
    printf("Enter degree of the first filter: ");
    scanf("%d", &deg1);
    int A[deg1 + 1];
    printf("Enter coefficients (from constant term to x^%d):\n", deg1);
    for (int i = 0; i <= deg1; i++) scanf("%d", &A[i]);
    printf("\nEnter degree of the second filter: ");
    scanf("%d", &deg2);
    int B[deg2 + 1];
    printf("Enter coefficients (from constant term to x^%d):\n", deg2);
    for (int i = 0; i <= deg2; i++) scanf("%d", &B[i]);
    printf("\n--- Result ---\n");
    multiplyPolynomials(A, B, deg1, deg2);
    return 0;
}