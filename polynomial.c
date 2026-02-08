#include <stdio.h>
#define MAX_DEGREE 100
void addPolynomials(int poly1[], int deg1, int poly2[], int deg2, int result[], int *maxDeg) {
    *maxDeg = (deg1 > deg2) ? deg1 : deg2;
    for (int i = 0; i <= *maxDeg; i++) {
        int term1 = (i <= deg1) ? poly1[i] : 0;
        int term2 = (i <= deg2) ? poly2[i] : 0;
        result[i] = term1 + term2;
    }
}
void displayPolynomial(int poly[], int degree) {
    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            printf("%d(x^%d)", poly[i], i);
            if (i > 0) printf(" + ");
        }
    }
    printf("\n");
}
int main() {
    int regionA[MAX_DEGREE] = {0}, regionB[MAX_DEGREE] = {0}, totalLoad[MAX_DEGREE] = {0};
    int degA, degB, maxDeg;
    degA = 2;
    regionA[0] = 50; regionA[1] = 10; regionA[2] = 5;
    degB = 3;
    regionB[0] = 30; regionB[1] = 20; regionB[2] = 2; regionB[3] = 8;
    printf("Region A Load: ");
    displayPolynomial(regionA, degA);
    printf("Region B Load: ");
    displayPolynomial(regionB, degB);
    addPolynomials(regionA, degA, regionB, degB, totalLoad, &maxDeg);
    printf("--------------------------------------------------\n");
    printf("Combined Power Consumption: ");
    displayPolynomial(totalLoad, maxDeg);
    return 0;
}