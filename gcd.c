#include <stdio.h>
int calculateGCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return calculateGCD(b, a % b);
}

int main() {
    int num1 = 56, num2 = 98;
    printf("GCD of %d and %d is: %d\n", num1, num2, calculateGCD(num1, num2));
    return 0;
}
